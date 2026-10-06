#!/usr/bin/env bash

# Repository Root Directory
REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

CXX="${CXX:-g++}"
CXXFLAGS="-std=c++20 -Wall -Wextra -O2"

JOBS="${JOBS:-$(nproc 2>/dev/null || echo 4)}"
STRICT=0
MODULES=()

# Parse CLI arguments
while [[ $# -gt 0 ]]; do
    case "$1" in
        -j|--jobs)
            JOBS="$2"
            shift 2
            ;;
        --strict)
            STRICT=1
            CXXFLAGS="${CXXFLAGS} -Werror"
            shift
            ;;
        -h|--help)
            echo "Usage: $0 [-j JOBS] [--strict] [MODULE_OR_FILE ...]"
            echo "Options:"
            echo "  -j, --jobs N   Number of parallel jobs (default: $(nproc 2>/dev/null || echo 4))"
            echo "  --strict       Treat warnings as errors (-Werror)"
            echo "  -h, --help     Show this help message"
            exit 0
            ;;
        *)
            MODULES+=("$1")
            shift
            ;;
    esac
done

if [ ${#MODULES[@]} -eq 0 ]; then
    MODULES=(
        "0_basics"
        "1_array"
        "2_matrix"
        "3_string"
        "4_search_sort"
        "5_linklist"
        "6_binary_tree"
        "7_bst"
        "8_greedy"
        "9_backtracking"
        "10_stack_queues"
        "11_heap"
        "12_graph"
        "13_Trie"
        "14_dynamic_programming"
        "15_bit_manipulation"
    )
fi

TMP_DIR=$(mktemp -d /tmp/dsa_test_suite.XXXXXX)
trap 'rm -rf "${TMP_DIR}"' EXIT INT TERM

TOTAL=0
PASSED=0
FAILED=0
FAILED_FILES=()

START_TIME=$(date +%s)

echo "=========================================================="
echo " Starting DSA C++ (C++20) Test Suite"
echo " Compiler:    C++: ${CXX}"
echo " Root:        ${REPO_ROOT}"
echo " Parallelism: ${JOBS} concurrent jobs"
if [ ${STRICT} -eq 1 ]; then
    echo " Strict Mode: Enabled (-Werror)"
fi
echo "=========================================================="

for mod in "${MODULES[@]}"; do
    # Check if target is an individual file
    if [ -f "${mod}" ] || [ -f "${REPO_ROOT}/${mod}" ]; then
        target_file="${mod}"
        [ ! -f "${target_file}" ] && target_file="${REPO_ROOT}/${mod}"
        files=("${target_file}")
        mod_name="$(basename "$(dirname "${target_file}")")/$(basename "${target_file}")"
    else
        MOD_PATH="${REPO_ROOT}/${mod}"
        if [ ! -d "${MOD_PATH}" ]; then
            echo "Module directory not found: ${MOD_PATH}"
            continue
        fi
        mod_name="${mod}"
        mapfile -t files < <(find "${MOD_PATH}" -maxdepth 1 -name "*.cpp" | sort)
    fi

    echo ""
    echo ">> Testing Module: ${mod_name}"
    MOD_COUNT=${#files[@]}
    MOD_PASS=0

    running_jobs=0
    declare -A job_files

    for f in "${files[@]}"; do
        TOTAL=$((TOTAL + 1))
        (
            bin="${TMP_DIR}/bin_${BASHPID}"
            log="${TMP_DIR}/log_${BASHPID}.txt"
            compile_cmd="${CXX} ${CXXFLAGS} \"$f\" -o \"${bin}\""

            if eval "${compile_cmd}" >"${log}" 2>&1 && "${bin}" >>"${log}" 2>&1; then
                rm -f "${bin}" "${log}"
                exit 0
            else
                rm -f "${bin}"
                exit 1
            fi
        ) &
        pid=$!
        job_files[$pid]="$f"
        running_jobs=$((running_jobs + 1))

        if [ $running_jobs -ge $JOBS ]; then
            wait -n -p finished_pid
            status=$?
            file="${job_files[$finished_pid]}"
            if [ $status -eq 0 ]; then
                MOD_PASS=$((MOD_PASS + 1))
            else
                FAILED=$((FAILED + 1))
                FAILED_FILES+=("$file")
                echo "   [FAIL] $(basename "$file")"
                log="${TMP_DIR}/log_${finished_pid}.txt"
                if [ -f "$log" ]; then
                    sed 's/^/     /' "$log"
                    rm -f "$log"
                fi
            fi
            running_jobs=$((running_jobs - 1))
            unset "job_files[$finished_pid]"
        fi
    done

    while [ $running_jobs -gt 0 ]; do
        wait -n -p finished_pid
        status=$?
        file="${job_files[$finished_pid]}"
        if [ $status -eq 0 ]; then
            MOD_PASS=$((MOD_PASS + 1))
        else
            FAILED=$((FAILED + 1))
            FAILED_FILES+=("$file")
            echo "   [FAIL] $(basename "$file")"
            log="${TMP_DIR}/log_${finished_pid}.txt"
            if [ -f "$log" ]; then
                sed 's/^/     /' "$log"
                rm -f "$log"
            fi
        fi
        running_jobs=$((running_jobs - 1))
        unset "job_files[$finished_pid]"
    done

    PASSED=$((PASSED + MOD_PASS))
    echo "   Passed: ${MOD_PASS}/${MOD_COUNT}"
    unset job_files
done

END_TIME=$(date +%s)
DURATION=$((END_TIME - START_TIME))

echo ""
echo "=========================================================="
echo " Test Suite Summary:"
echo " Total files tested: ${TOTAL}"
echo " Passed:             ${PASSED}"
echo " Failed:             ${FAILED}"
echo " Duration:           ${DURATION}s"
echo "=========================================================="

if [ ${FAILED} -gt 0 ]; then
    echo "Failed files:"
    for f in "${FAILED_FILES[@]}"; do
        echo "  - $f"
    done
    exit 1
fi

echo " All tests passed successfully!"
exit 0

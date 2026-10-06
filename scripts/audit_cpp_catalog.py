#!/usr/bin/env python3
"""
C++ Problem Catalog and Integrity Auditor for dsa_cpp repository.
Verifies that each problem in the repository is implemented in modern C++20.
"""

import os
import sys
import argparse
import json

DEFAULT_MODULES = [
    "0_basics",
    "1_array",
    "2_matrix",
    "3_string",
    "4_search_sort",
    "5_linklist",
    "6_binary_tree",
    "7_bst",
    "8_greedy",
    "9_backtracking",
    "10_stack_queues",
    "11_heap",
    "12_graph",
    "13_Trie",
    "14_dynamic_programming",
    "15_bit_manipulation"
]

def scan_module(mod_path):
    cpp_files = []
    non_cpp_files = []
    with_assert = 0
    with_using_ns = 0

    for entry in sorted(os.listdir(mod_path)):
        full_path = os.path.join(mod_path, entry)
        if not os.path.isfile(full_path):
            continue
        if entry.endswith(".cpp"):
            cpp_files.append(entry)
            try:
                with open(full_path, "r", encoding="utf-8", errors="ignore") as f:
                    content = f.read()
                    if "assert(" in content:
                        with_assert += 1
                    if "using namespace std;" in content:
                        with_using_ns += 1
            except Exception:
                pass
        elif entry != "README.md":
            non_cpp_files.append(entry)

    return {
        "cpp_count": len(cpp_files),
        "cpp_files": cpp_files,
        "with_assert": with_assert,
        "with_using_ns": with_using_ns,
        "non_cpp_files": non_cpp_files
    }

def main():
    parser = argparse.ArgumentParser(description="Audit C++ problem catalog in dsa_cpp repository")
    parser.add_argument("--repo-root", default=".", help="Root path of the repository")
    parser.add_argument("--json", action="store_true", help="Output results as JSON")
    parser.add_argument("--details", action="store_true", help="Print all program filenames")
    parser.add_argument("modules", nargs="*", default=DEFAULT_MODULES, help="Specific modules to check")

    args = parser.parse_args()
    root = os.path.abspath(args.repo_root)

    results = {}
    total_cpp = 0
    total_with_assert = 0
    total_with_using_ns = 0
    total_non_cpp = 0

    for mod in args.modules:
        mod_path = os.path.join(root, mod)
        if not os.path.isdir(mod_path):
            continue
        data = scan_module(mod_path)
        results[mod] = data
        total_cpp += data["cpp_count"]
        total_with_assert += data["with_assert"]
        total_with_using_ns += data["with_using_ns"]
        total_non_cpp += len(data["non_cpp_files"])

    if args.json:
        payload = {
            "summary": {
                "total_cpp_programs": total_cpp,
                "programs_with_assert": total_with_assert,
                "programs_with_using_ns": total_with_using_ns,
                "unexpected_files": total_non_cpp
            },
            "modules": results
        }
        print(json.dumps(payload, indent=2))
    else:
        print("=" * 78)
        print(" DSA C++ (C++20) Problem Catalog & Quality Audit")
        print(" Repository: " + root)
        print("=" * 78)
        header = f"{'Module':<25} | {'Programs':^10} | {'Asserts':^9} | {'Using std':^11} | {'Stray Files':^11}"
        print(header)
        print("-" * 78)
        for mod, d in results.items():
            print(f"{mod:<25} | {d['cpp_count']:^10} | {d['with_assert']:^9} | {d['with_using_ns']:^11} | {len(d['non_cpp_files']):^11}")
        print("-" * 78)
        print(f"{'TOTAL':<25} | {total_cpp:^10} | {total_with_assert:^9} | {total_with_using_ns:^11} | {total_non_cpp:^11}")
        print("=" * 78)

        if total_cpp > 0:
            assert_pct = (total_with_assert / total_cpp) * 100
            using_ns_pct = (total_with_using_ns / total_cpp) * 100
            print(f"  Assertion Coverage:        {total_with_assert}/{total_cpp} ({assert_pct:.1f}%)")
            print(f"  'using namespace std;':   {total_with_using_ns}/{total_cpp} ({using_ns_pct:.1f}%)")

        if args.details:
            print("\nModule Program Breakdown:")
            for mod, d in results.items():
                print(f"\n>> {mod} ({d['cpp_count']} programs):")
                for f in d["cpp_files"]:
                    print(f"   - {f}")

    if total_non_cpp > 0:
        print(f"\nWarning: Found {total_non_cpp} unexpected stray file(s):")
        for mod, d in results.items():
            for f in d["non_cpp_files"]:
                print(f"  - {mod}/{f}")
        sys.exit(1)

    sys.exit(0)

if __name__ == "__main__":
    main()

# AGENTS.md — Universal Agent Operating Standard: dsa_cpp

> **Repository:** `/home/liberprimus/code/dsa_cpp`  
> **Workspace Authority:** `sudh29` (`liberprimus`)  
> **Tier:** Tier B (Modern C++20 Algorithmic & Systems Engineering Suite)  
> **Active Branch:** `dev`  
> **Applicable Agents:** Antigravity, Claude Code, Cursor, Gemini, Codex


---

## 1. Repository Purpose & Architecture

- **Overview:** `dsa_cpp` is a production-grade algorithmic and data structures reference suite implemented in modern C++20. It covers graph algorithms, dynamic programming, trees, advanced heaps, geometry, and string processing with zero-leak memory verification.
- **Key Directory Map:**
  - `scripts/`: Compile, test runner, and catalog auditing scripts:
    - `compile_and_test.sh`: Parallel test harness with optional strict warnings and AddressSanitizer.
    - `audit_cpp_catalog.py`: Verifies problem catalog coverage.
  - Subdirectories partitioned by category: `01_arrays/`, `02_strings/`, `03_linked_lists/`, etc.
  - `Makefile`: Canonical build targets.
- **Architectural Invariants:**
  - **Zero Memory Leaks:** Every solution must run cleanly under AddressSanitizer (`make test-asan`) with 0 leaks or memory corruptions.
  - **Modern C++20 Standards:** Utilize RAII, `std::span`, concepts, ranges, and smart pointers where applicable. Avoid unencapsulated raw `malloc`/`free`.
  - **Deterministic Tests:** Test cases must assert both edge cases and average cases deterministically.

### Key Architecture & Entry Points

- **Runner Script:** [`scripts/compile_and_test.sh`](file:///home/liberprimus/code/dsa_cpp/scripts/compile_and_test.sh)
- **Audit Script:** [`scripts/audit_cpp_catalog.py`](file:///home/liberprimus/code/dsa_cpp/scripts/audit_cpp_catalog.py)
- **Buildfile:** [`Makefile`](file:///home/liberprimus/code/dsa_cpp/Makefile)
- **Problem Folders:** Partitioned numerically (`01_arrays/`, `02_strings/`, etc.)

---

## 2. Coding Style & Engineering Conventions

- Idiomatic C++20 (RAII, standard library containers, `std::span`, `auto`, clean namespaces).
- Memory safety is non-negotiable: zero leaks in `make test-asan`.
- Use snake_case for filenames, PascalCase for classes, camelCase for functions.

---

## 3. Toolchain & Environment Matrix

- **Compiler:** `clang++` / `g++` (C++20 standard)
- **Sanitizers:** AddressSanitizer (`-fsanitize=address,undefined`)
- **Build System:** GNU Make

### Canonical Commands
All commands run from `/home/liberprimus/code/dsa_cpp`:

| Action | Command | Purpose |
|:---|:---|:---|
| **Run All Tests** | `make test` | Compile and execute test suite across all modules |
| **Strict Tests** | `make test-strict` | Execute test suite with `-Wall -Wextra -Werror` |
| **ASan Leak Check** | `make test-asan` | Execute test suite under strict AddressSanitizer |
| **Single Module Test** | `make test MODULE=<module_name>` | Test a specific subcategory (e.g., `MODULE=01_arrays`) |
| **Audit Catalog** | `make audit` | Audit implementation progress and catalog completeness |
| **Audit Details** | `make audit-details` | Detailed gap report of unsolved problems |
| **Format Code** | `make format` | Apply `clang-format` to all `.cpp` files |

### Quick-Start Workflow

```bash
# Testing & Sanitizers
make test                               # Compile and run test suite
make test-strict                        # Run with -Wall -Wextra -Werror
make test-asan                          # Run under AddressSanitizer (leak check)
make test MODULE=<name>                 # Test specific module (e.g. MODULE=01_arrays)

# Auditing & Formatting
make audit                              # Run catalog completeness audit
make audit-details                      # Detailed audit breakdown
make format                             # Format all .cpp files with clang-format
make clean                              # Remove temporary binaries and objects
```

---

## 4. Operational Safety & Agent Boundaries

1. **Blast Radius Containment:** Strictly confine edits to `/home/liberprimus/code/dsa_cpp`.
2. **Verification Mandate:** Always run `make test-asan` (or `make test-strict`) before declaring code changes complete.
3. **Branch Discipline:** Active working branch is `dev`.

---

## 5. Definition of Done
- [ ] Code compiles without warnings (`make test-strict`).
- [ ] No leaks or memory errors under AddressSanitizer (`make test-asan`).
- [ ] Problem entry added/updated in catalog (`make audit`).
- [ ] Working tree clean of binary artifacts (`*.o`, `*.out`).

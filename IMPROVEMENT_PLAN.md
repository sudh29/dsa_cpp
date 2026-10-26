---
repo: dsa_cpp
review_date: 2026-10-24
current_score: 9.3
target_score: 9.7
---

# Repository Improvement Plan: `dsa_cpp`

> **Hiring-Bar Audit Target:** AI Engineer / Staff IC / Systems Architect (~8 years experience)  
> **Evaluation Threshold:** 9.5+ / 10.0  
> **Current Overall Score:** **9.3 / 10.0** (Delta to 9.5 bar: +0.2)

---

## 1. Baseline Scorecard & Gaps

| # | Criterion | Weight | Score | Primary Gap / Finding |
|---|---|:---:|:---:|---|
| 1 | **Correctness & functionality** | 15% | **9.6** | Flawless 390-program execution passing 100% of test suites in 46 seconds (`scripts/compile_and_test.sh -j 12`). Gap: Assertions focus heavily on sample expected values rather than boundary/stress test invariants. |
| 2 | **Architecture & design** | 15% | **9.4** | Clean 16-module hierarchy; self-contained files with zero `using namespace std;` pollution. Gap: Some utilities (e.g. linked list display / tree node allocators) are re-implemented across files rather than shared in a common header template. |
| 3 | **Code quality** | 10% | **8.8** | Modern C++20 standard library usage. Gap: `make check-format` (`clang-format --dry-run --Werror`) fails across multiple modules; mixed snake_case and PascalCase filename conventions. |
| 4 | **Testing & CI** | 15% | **9.0** | Comprehensive automated parallel test runner and multi-compiler matrix (`g++-12`, `clang-14`, `clang-14-asan`). Gap: Remote CI only runs AddressSanitizer on 3 out of 16 modules; lacks `clang-tidy` static analysis gate and automated code coverage reporting. |
| 5 | **Security** | 10% | **9.8** | Zero committed secrets or credentials. Zero third-party dependencies. Verified ASan/UBSan clean execution. |
| 6 | **Reliability & performance** | 10% | **9.4** | Fast execution, -O2 optimization, memory-safe pointer traversal. Gap: Sanitizer execution across all 390 programs is not run as part of standard PR gating. |
| 7 | **DevEx & ops** | 10% | **9.2** | Rich Makefile with parallel autodetect. Gap: Lacks containerized build runner (Dockerfile / devcontainer) and pre-commit hook configuration. |
| 8 | **Documentation** | 5% | **9.6** | 11KB root README with matrix and 16 per-module README guides. Gap: Missing canonical LeetCode problem IDs and difficulty tagging. |
| 9 | **Repo hygiene** | 5% | **9.2** | MIT License, .clang-format present. Gap: Formatting rules not enforced repo-wide; untracked files present in working directory. |
| 10 | **Impact & clarity** | 5% | **9.6** | Monumental scope: 390 verified C++20 problem implementations with 100% automated test suites. |

---

## 2. Ranked Gaps (Impact ÷ Effort)

| Rank | Gap Description | Affected Criterion | Impact | Effort | Priority |
|:---:|---|---|:---:|:---:|:---:|
| 1 | Apply `clang-format` across all 390 files to resolve `make check-format` | Code Quality, Hygiene | High | S | Phase 1 |
| 2 | Expand CI AddressSanitizer matrix to cover all 16 modules | Testing & CI, Reliability | High | S | Phase 1 |
| 3 | Add `clang-format` and `clang-tidy` checking step to `.github/workflows/ci.yml` | Testing & CI, Quality | High | M | Phase 1 |
| 4 | Add `.pre-commit-config.yaml` for pre-push formatting validation | DevEx & Ops, Hygiene | Medium | S | Phase 2 |
| 5 | Add Dockerfile and DevContainer configuration for hermetic builds | DevEx & Ops | Medium | M | Phase 2 |
| 6 | Enrich `scripts/audit_cpp_catalog.py` with difficulty ratings & problem links | Documentation, Impact | Low | M | Phase 3 |

---

## 3. Phased Action Plan

### Phase 1: MVP-Essential (Target: Cross 9.5 Bar)

Focus on resolving code formatting failures, enforcing CI hygiene, and ensuring full AddressSanitizer verification across all modules.

#### Task 1.1: Repo-Wide Clang-Format Enforcement
- **Description:** Run `make format` across all `.cpp` and `.h` files using the existing `.clang-format` rules and ensure `make check-format` exits with code 0.
- **Why:** Code formatting is currently failing the repository's own quality gate in `make check-format`.
- **Files Affected:** All `.cpp` files in `0_basics/` through `15_bit_manipulation/`.
- **Acceptance Criteria:** `make check-format` passes with zero violations across all 390 files.
- **Effort:** Small (automated via `make format`).
- **Score Delta:** Code Quality: +0.6, Repo Hygiene: +0.4.

#### Task 1.2: Full-Matrix AddressSanitizer CI Automation
- **Description:** Update [.github/workflows/ci.yml](file:///home/liberprimus/code/dsa_cpp/.github/workflows/ci.yml) to execute AddressSanitizer and UndefinedBehaviorSanitizer across all 16 modules (using parallel jobs) rather than the restricted 3-module subset.
- **Why:** Full ASan coverage prevents silent memory corruption and buffer overflows in complex pointer structures (linked lists, graphs, trees).
- **Files Affected:** `.github/workflows/ci.yml`.
- **Acceptance Criteria:** CI matrix step runs `bash scripts/compile_and_test.sh -j $(nproc) --strict --sanitize` on all modules.
- **Effort:** Small.
- **Score Delta:** Testing & CI: +0.4, Reliability & Performance: +0.2.

#### Task 1.3: CI Formatting & Lint Gate
- **Description:** Add a dedicated `lint-and-format` job in [.github/workflows/ci.yml](file:///home/liberprimus/code/dsa_cpp/.github/workflows/ci.yml) that verifies `clang-format --dry-run --Werror`.
- **Why:** Guarantees formatting consistency on every push and PR.
- **Files Affected:** `.github/workflows/ci.yml`.
- **Acceptance Criteria:** Push/PR fails if code formatting diverges from `.clang-format`.
- **Effort:** Small.
- **Score Delta:** Testing & CI: +0.2.

---

### Phase 2: Hardening & DevEx (Target: 9.6+)

#### Task 2.1: Pre-Commit Hook Configuration
- **Description:** Introduce `.pre-commit-config.yaml` with hooks for `clang-format`, trailing whitespace trimming, end-of-file fixers, and catalog audit validation.
- **Why:** Eliminates formatting drift locally before code reaches remote CI.
- **Files Affected:** `.pre-commit-config.yaml`, `Makefile`.
- **Acceptance Criteria:** `pre-commit run --all-files` passes cleanly.
- **Effort:** Small.
- **Score Delta:** DevEx & Ops: +0.3.

#### Task 2.2: Hermetic Containerized Build Environment
- **Description:** Create a lightweight `Dockerfile` (Ubuntu 24.04 with GCC 13, Clang 18, Make, CMake, Python 3) and `.devcontainer/devcontainer.json`.
- **Why:** Allows any engineer on macOS or Windows to immediately compile and test all 390 programs with exact toolchain parity.
- **Files Affected:** `Dockerfile`, `.dockerignore`, `.devcontainer/devcontainer.json`.
- **Acceptance Criteria:** `docker build -t dsa-cpp . && docker run --rm dsa-cpp make test-strict` succeeds.
- **Effort:** Medium.
- **Score Delta:** DevEx & Ops: +0.3.

---

### Phase 3: Nice-to-Have & Telemetry (Target: 9.7+)

#### Task 3.1: Canonical Problem Metadata & Cross-Referencing
- **Description:** Update `scripts/audit_cpp_catalog.py` to index LeetCode problem equivalents, difficulty tags (Easy/Medium/Hard), and primary algorithmic paradigms (e.g. Two Pointers, Monotonic Queue).
- **Why:** Elevates the catalog from an internal practice suite to an industry-grade algorithmic benchmark.
- **Files Affected:** `scripts/audit_cpp_catalog.py`, `README.md`.
- **Acceptance Criteria:** `make audit` displays difficulty distribution breakdown and problem mappings.
- **Effort:** Medium.
- **Score Delta:** Documentation: +0.2, Impact & Clarity: +0.2.

---

## 4. Projected Score Progression

| Phase | Milestone | Expected Score | Delta |
|:---:|---|:---:|:---:|
| **Baseline** | Current audit baseline | **9.3** | — |
| **Phase 1** | Formatted code, full ASan CI gate, CI format check | **9.5** | +0.2 |
| **Phase 2** | Pre-commit hooks, Dockerfile & devcontainer | **9.6** | +0.1 |
| **Phase 3** | Problem metadata taxonomy & benchmark auditor | **9.7** | +0.1 |

---

## 5. Definition of Done for Reaching 9.5+

- [ ] All 390 `.cpp` files formatted with `clang-format` according to `.clang-format`.
- [ ] `make check-format` exits with code 0.
- [ ] CI workflow runs full AddressSanitizer and UB Sanitizer across all 16 modules.
- [ ] CI workflow enforces `make check-format` on PRs and pushes.
- [ ] Zero compiler warnings with `-std=c++20 -Wall -Wextra -Werror`.

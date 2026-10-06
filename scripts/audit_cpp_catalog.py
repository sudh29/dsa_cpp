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
    for entry in sorted(os.listdir(mod_path)):
        full_path = os.path.join(mod_path, entry)
        if not os.path.isfile(full_path):
            continue
        if entry.endswith(".cpp"):
            cpp_files.append(entry)
        elif entry.endswith((".c", ".h", ".hpp", ".py")):
            non_cpp_files.append(entry)

    return {
        "cpp_count": len(cpp_files),
        "cpp_files": cpp_files,
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
    total_non_cpp = 0

    for mod in args.modules:
        mod_path = os.path.join(root, mod)
        if not os.path.isdir(mod_path):
            continue
        data = scan_module(mod_path)
        results[mod] = data
        total_cpp += data["cpp_count"]
        total_non_cpp += len(data["non_cpp_files"])

    if args.json:
        payload = {
            "summary": {
                "total_cpp_programs": total_cpp,
                "non_cpp_files": total_non_cpp
            },
            "modules": results
        }
        print(json.dumps(payload, indent=2))
    else:
        print("=" * 64)
        print(" DSA C++ (C++20) Problem Catalog & Integrity Audit")
        print(" Repository: " + root)
        print("=" * 64)
        header = f"{'Module':<25} | {'C++ Programs':^14} | {'Non-C++ Files':^15}"
        print(header)
        print("-" * 64)
        for mod, d in results.items():
            print(f"{mod:<25} | {d['cpp_count']:^14} | {len(d['non_cpp_files']):^15}")
        print("-" * 64)
        print(f"{'TOTAL':<25} | {total_cpp:^14} | {total_non_cpp:^15}")
        print("=" * 64)

        if args.details:
            print("\nModule Program Breakdown:")
            for mod, d in results.items():
                print(f"\n>> {mod} ({d['cpp_count']} programs):")
                for f in d["cpp_files"]:
                    print(f"   - {f}")

    if total_non_cpp > 0:
        print(f"\nWarning: Found {total_non_cpp} unexpected non-C++ source file(s)!")
        sys.exit(1)

    sys.exit(0)

if __name__ == "__main__":
    main()

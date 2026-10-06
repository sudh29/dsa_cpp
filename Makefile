.PHONY: all test test-strict test-asan audit audit-details format check-format clean help

JOBS ?= $(shell nproc 2>/dev/null || echo 4)
STRICT ?= 0
SANITIZE ?= 0
MODULE ?=

ARGS := -j $(JOBS)
ifeq ($(STRICT),1)
	ARGS += --strict
endif
ifeq ($(SANITIZE),1)
	ARGS += --sanitize
endif
ifneq ($(MODULE),)
	ARGS += $(MODULE)
endif

all: test

test:
	@bash scripts/compile_and_test.sh $(ARGS)

test-strict:
	@bash scripts/compile_and_test.sh -j $(JOBS) --strict $(if $(MODULE),$(MODULE),)

test-asan:
	@bash scripts/compile_and_test.sh -j $(JOBS) --strict --sanitize $(if $(MODULE),$(MODULE),)

audit:
	@python3 scripts/audit_cpp_catalog.py

audit-details:
	@python3 scripts/audit_cpp_catalog.py --details

format:
	@which clang-format >/dev/null 2>&1 || (echo "clang-format not installed"; exit 1)
	@find . -maxdepth 2 -name "*.cpp" -exec clang-format -i {} +
	@echo "Formatting complete."

check-format:
	@which clang-format >/dev/null 2>&1 || (echo "clang-format not installed"; exit 1)
	@find . -maxdepth 2 -name "*.cpp" -exec clang-format --dry-run --Werror {} +
	@echo "All files conform to clang-format."

clean:
	@rm -rf /tmp/dsa_test_suite.* /tmp/dsa_test_bin build bin *.o *.out
	@echo "Clean completed."

help:
	@echo "Available targets:"
	@echo "  make test [JOBS=N] [STRICT=1] [SANITIZE=1] [MODULE=name] - Compile and execute test suite"
	@echo "  make test-strict [MODULE=name]                          - Run with -Werror enabled"
	@echo "  make test-asan [MODULE=name]                            - Run with AddressSanitizer & UBSan"
	@echo "  make audit                                              - Audit C++ problem catalog"
	@echo "  make audit-details                                      - Show all C++ program filenames"
	@echo "  make format                                             - Auto-format C++ files with clang-format"
	@echo "  make check-format                                       - Validate formatting without modifying"
	@echo "  make clean                                              - Remove temporary build artifacts"
	@echo "  make help                                               - Show this help message"

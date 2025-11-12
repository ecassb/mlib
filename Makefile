# mlib - C Standard Library Implementation
# Makefile for building static and shared libraries

# Compiler and tools
CC := gcc
AR := ar
RANLIB := ranlib

# Directories
SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := obj
LIB_DIR := lib
TEST_DIR := tests
BENCHMARK_DIR := benchmarks

# Library name
LIB_NAME := mlib
STATIC_LIB := $(LIB_DIR)/lib$(LIB_NAME).a
SHARED_LIB := $(LIB_DIR)/lib$(LIB_NAME).so

# Compiler flags
CFLAGS := -Wall -Wextra -Werror -pedantic -std=c23
CFLAGS += -fPIC  # Position independent code for shared library
CFLAGS_LIB := -I $(INCLUDE_DIR)
CFLAGS_TEST := -iquote $(INCLUDE_DIR) 
CFLAGS_TEST += -iquote tests/inlcude

# Debug/Release flags
DEBUG_FLAGS := -g -O0 -DDEBUG
RELEASE_FLAGS := -O2 -DNDEBUG

# Default to debug build
BUILD_TYPE ?= debug
ifeq ($(BUILD_TYPE),release)
    CFLAGS += $(RELEASE_FLAGS)
else
    CFLAGS += $(DEBUG_FLAGS)
endif

# Source files organized by category
STRING_SRCS := $(wildcard $(SRC_DIR)/string/*.c)
STDIO_SRCS := $(wildcard $(SRC_DIR)/stdio/*.c)
STDLIB_SRCS := $(wildcard $(SRC_DIR)/stdlib/*.c)
MATH_SRCS := $(wildcard $(SRC_DIR)/math/*.c)
CTYPE_SRCS := $(wildcard $(SRC_DIR)/ctype/*.c)
TIME_SRCS := $(wildcard $(SRC_DIR)/time/*.c)
SETJMP_SRCS := $(wildcard $(SRC_DIR)/setjmp/*.c)
SIGNAL_SRCS := $(wildcard $(SRC_DIR)/signal/*.c)

# All source files
SRCS := $(STRING_SRCS) $(STDIO_SRCS) $(STDLIB_SRCS) $(MATH_SRCS) \
        $(CTYPE_SRCS) $(TIME_SRCS) $(SETJMP_SRCS) $(SIGNAL_SRCS)

# Object files (maintain directory structure in obj/)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Test files
TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)
TEST_BINS := $(TEST_SRCS:$(TEST_DIR)/%.c=$(TEST_DIR)/%)

# Benchmark files
BENCHMARK_SRCS := $(wildcard $(BENCHMARK_DIR)/*.c)
BENCHMARK_BINS := $(BENCHMARK_SRCS:$(BENCHMARK_DIR)/%.c=$(BENCHMARK_DIR)/%)

# Default target
.PHONY: all clean test benchmark install uninstall help
.DEFAULT_GOAL := all

all: $(STATIC_LIB) $(SHARED_LIB)

# Create directories
$(OBJ_DIR) $(LIB_DIR):
	mkdir -p $@

$(OBJ_DIR)/string $(OBJ_DIR)/stdio $(OBJ_DIR)/stdlib $(OBJ_DIR)/math \
$(OBJ_DIR)/ctype $(OBJ_DIR)/time $(OBJ_DIR)/setjmp $(OBJ_DIR)/signal: | $(OBJ_DIR)
	mkdir -p $@

# Static library
$(STATIC_LIB): $(OBJS) | $(LIB_DIR)
	$(AR) rcs $@ $^
	$(RANLIB) $@

# Shared library
$(SHARED_LIB): $(OBJS) | $(LIB_DIR)
	$(CC) -shared -o $@ $^

# Object file compilation with automatic dependency tracking
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)/string $(OBJ_DIR)/stdio $(OBJ_DIR)/stdlib $(OBJ_DIR)/math $(OBJ_DIR)/ctype $(OBJ_DIR)/time $(OBJ_DIR)/setjmp $(OBJ_DIR)/signal
	$(CC) $(CFLAGS) $(CFLAGS_LIB) -nostdinc -MMD -MP -c $< -o $@

# Include dependency files
-include $(OBJS:.o=.d)

# Test targets
test: $(TEST_BINS)
	@echo "Running tests..."
	@for test in $(TEST_BINS); do \
		echo "Running $$test"; \
		./$$test || exit 1; \
	done
	@echo "All tests passed!"

$(TEST_DIR)/%: $(TEST_DIR)/%.c $(STATIC_LIB)
	$(CC) $(CFLAGS) $(CFLAGS_TEST) $< -L$(LIB_DIR) -lm -l$(LIB_NAME) -o $@

# Benchmark targets
benchmark: $(BENCHMARK_BINS)
	@echo "Running benchmarks..."
	@for bench in $(BENCHMARK_BINS); do \
		echo "Running $$bench"; \
		./$$bench; \
	done

$(BENCHMARK_DIR)/%: $(BENCHMARK_DIR)/%.c $(STATIC_LIB)
	$(CC) $(CFLAGS) -O3 $< -L$(LIB_DIR) -l$(LIB_NAME) -o $@

# Debug build
debug:
	$(MAKE) BUILD_TYPE=debug

# Release build
release:
	$(MAKE) BUILD_TYPE=release

# Clean targets
clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR)
	rm -f $(TEST_BINS) $(BENCHMARK_BINS)
	rm -f $(TEST_DIR)/*.d $(BENCHMARK_DIR)/*.d

clean-all: clean
	find . -name "*.o" -delete
	find . -name "*.d" -delete
	find . -name "*.a" -delete
	find . -name "*.so" -delete

# Install library (optional)
PREFIX ?= /usr/local
INSTALL_LIB_DIR := $(PREFIX)/lib
INSTALL_INCLUDE_DIR := $(PREFIX)/include

install: $(STATIC_LIB) $(SHARED_LIB)
	install -d $(INSTALL_LIB_DIR)
	install -d $(INSTALL_INCLUDE_DIR)
	install -m 644 $(STATIC_LIB) $(INSTALL_LIB_DIR)/
	install -m 755 $(SHARED_LIB) $(INSTALL_LIB_DIR)/
	cp -r $(INCLUDE_DIR)/* $(INSTALL_INCLUDE_DIR)/
	ldconfig 2>/dev/null || true

uninstall:
	rm -f $(INSTALL_LIB_DIR)/lib$(LIB_NAME).a
	rm -f $(INSTALL_LIB_DIR)/lib$(LIB_NAME).so
	rm -rf $(INSTALL_INCLUDE_DIR)/mlib

# Development helpers
format:
	find $(SRC_DIR) $(INCLUDE_DIR) $(TEST_DIR) -name "*.c" -o -name "*.h" | xargs clang-format -i

lint:
	find $(SRC_DIR) -name "*.c" | xargs cppcheck --enable=all --std=c99

# Information targets
info:
	@echo "mlib Build Information:"
	@echo "  Build type: $(BUILD_TYPE)"
	@echo "  Compiler: $(CC)"
	@echo "  Flags: $(CFLAGS)"
	@echo "  Source files: $(words $(SRCS))"
	@echo "  Object files: $(words $(OBJS))"
	@echo "  Static library: $(STATIC_LIB)"
	@echo "  Shared library: $(SHARED_LIB)"

help:
	@echo "mlib - C Standard Library Implementation"
	@echo ""
	@echo "Available targets:"
	@echo "  all        - Build both static and shared libraries (default)"
	@echo "  debug      - Build debug version with symbols and no optimization"
	@echo "  release    - Build optimized release version"
	@echo "  test       - Compile and run all tests"
	@echo "  benchmark  - Compile and run all benchmarks"
	@echo "  clean      - Remove build artifacts"
	@echo "  clean-all  - Remove all generated files"
	@echo "  install    - Install library to system (requires sudo)"
	@echo "  uninstall  - Remove library from system (requires sudo)"
	@echo "  format     - Format source code with clang-format"
	@echo "  lint       - Run static analysis with cppcheck"
	@echo "  info       - Show build information"
	@echo "  help       - Show this help message"
	@echo ""
	@echo "Build options:"
	@echo "  BUILD_TYPE=debug|release  - Set build type (default: debug)"
	@echo "  PREFIX=/path/to/install   - Set installation prefix (default: /usr/local)"
	@echo ""
	@echo "Examples:"
	@echo "  make                      - Build debug version"
	@echo "  make release             - Build release version"
	@echo "  make test                - Run tests"
	@echo "  make clean && make       - Clean rebuild" 
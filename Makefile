CPUS ?= $(shell (nproc --all || sysctl -n hw.ncpu) 2>/dev/null || echo 1)
MAKEFLAGS += --jobs=$(CPUS)

.PHONY: clean build run

clean:
	bazel clean


build:
	CC=clang++ bazel build :aom

run:
	CC=clang++ bazel run :aom


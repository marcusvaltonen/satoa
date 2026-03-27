#!/bin/bash
usage="$(basename "$0") [-n] [-h] -- Build script for satoa

Parameters:
    -h, --help         Show this help message"

set -euo pipefail

while [[ "$#" -gt 0 ]]; do
    case $1 in
        -h|--help) echo "$usage"; exit 0 ;;
        *) echo "Unknown parameter passed: $1"; exit 1 ;;
    esac
    shift
done

build_dir=_build

# Display information
echo "Configuring build for scale-aware trilateration"
echo "  - Build directory: $build_dir"

# Change directory depending on whether it is debug or release mode
mkdir -p $build_dir && cd $build_dir

cmake ..

# Build (for Make on Unix equivalent to `make -j $(nproc)`)
if [[ "$OSTYPE" == "darwin"* ]]; then
  # Mac OSX does not have nproc
  cmake --build . -- -j $(sysctl -n hw.logicalcpu)
else
  cmake --build . -- -j $(nproc)
fi


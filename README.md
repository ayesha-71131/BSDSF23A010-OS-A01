# BSDSF23A010-OS-A01 - Operating Systems Programming Assignment 01

A general-purpose utility library `libmyutils` providing string and file manipulation functions, demonstrating multi-file C project development, static/dynamic library creation, and professional software distribution.

## Project Structure

```
BSDSF23A010-OS-A01/
├── src/       # Source code
├── include/   # Header files
├── lib/       # Compiled libraries (.a, .so)
├── bin/       # Executable programs
├── obj/       # Object files
├── man/       # Manual pages
└── REPORT.md  # Analysis report
```

## Features Implemented

- String Functions: `mystrlen`, `mystrcpy`, `mystrncpy`, `mystrcat`
- File Functions: `wordCount`, `mygrep`
- Build Systems: Multi-file compilation, static library (.a), dynamic library (.so)
- Documentation: Linux man pages for all functions
- Installation: System-wide installation via Makefile

## Build Instructions

```bash
# Build the project
make all

# Run the program
make run

# Install system-wide (requires sudo)
sudo make install

# Clean build artifacts
make clean
```

## Usage

After installation:

```bash
# Run the client program
client

# View function documentation
man mystrlen
man mystrcpy
man wordCount
man mygrep
```

## Development Branches

- main - Final integrated version
- multiple-build - Multi-file compilation
- static-build - Static library implementation
- dynamic-build - Dynamic library implementation
- documentation - Man pages and installation

## Version History

- v0.1.1-multifile: Basic multi-file compilation
- v0.2.1-static: Static library build
- v0.3.1-dynamic: Dynamic library build
- v0.4.1-final: Final version with installation

## Author

Ayesha Waheed - BSDSF23A010

# utils (C)

A small, header-driven C utilities library that provides common data structures and helper modules (vector, stack, queue, BST, strings), plus an optional arena allocator.

## What's included

### Data structures
- **Vector** (`vector_t`) — dynamic array with push/pop, insert/erase, iterators.
- **Stack** (`stack_s`) — LIFO stack.
- **Queue** (`queue_t`) — circular-buffer style queue with resize.
- **Binary Search Tree** (`bst_t`) — add/remove/find, traversal printing, copy/compare, and mapping over nodes.

### Utilities
- **Arena allocator** (`arena_t`) — simple first-fit allocator backed by `mmap` on POSIX systems.
- **Strings** (`string_t`) — owned string type with append/concat/compare and arena-backed variants.
- **Matrix / math / algorithms** — assorted helpers (see headers in `include/` for the full API surface).

## Project layout

```text
.
├── include/        # public headers (APIs)
├── src/            # library sources
├── tests/          # basic tests / examples
├── build/          # build outputs (generated)
└── Makefile
```

## Build

This repo ships with a simple `Makefile` that builds the test executable:

```bash
make
./test
```

Clean:

```bash
make clean
```

To make use in your own project, just add the header file and associated C file to your project code.

### Requirements
- POSIX `mmap` support if you use the arena allocator (Linux/macOS).

## Usage

Include the headers you need from `include/` and compile/link the sources from `src/` (or build the library in your own build system).

## Testing

There is a `tests/` folder and the default `make` target produces an executable named `test`:

```bash
make
./test
```
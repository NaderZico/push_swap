# push_swap

Sorts a stack of integers using a limited set of operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) while keeping the number of moves as low as possible. Built at 42 Abu Dhabi.

## Approach
- Validates and normalizes input (duplicates, non-numeric values, integer overflow)
- Maps each value to its sorted rank for simpler comparisons
- Uses a small-stack sort for 2 to 5 elements and a chunk-based strategy for larger sets

## Build and run
```bash
make
./push_swap 4 67 3 87 23
```

The program prints the sequence of operations needed to sort the stack.

```bash
make clean   # remove object files
make fclean  # remove object files and binary
make re      # rebuild from scratch
```

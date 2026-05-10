# Sorting Performance Benchmarks

This document tracks the performance of various sorting algorithm implementations.
All benchmarks were performed on the **Win32 (x86)** architecture.

## Benchmark Results

### Dataset Size: $N=20,000$

| Rank | Algorithm Implementation  | Execution Time (ms) | Speed vs. Baseline |
| :--- | :------------------------ | :------------------ | :----------------- |
| 1    | Common insertion sort C++ | 32.073              | 11.33x             |
| 2    | Bubble sort quicker ASM   | 107.866             | 3.37x              |
| 3    | Bubble sort quicker C++   | 108.251             | 3.36x              |
| 4    | Common selection sort C++ | 187.343             | 1.94x              |
| 5    | Common bubble sort C++    | 363.349             | Baseline           |
| 6    | AI Generated Bubble Sort  | 367.014             | 0.98x              |
| 7    | Optimized Bubble sort C++ | 371.436             | 0.98x              |
| 8    | Optimized Bubble sort ASM | 508.268             | 0.71x              |

---

_Note: All values are measured in milliseconds. Baseline is the Common Bubble Sort C++ implementation._

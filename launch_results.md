# Sorting Performance Benchmarks

This document tracks the performance of various sorting algorithm implementations.
All benchmarks were performed on the **Win32 (x86)** architecture.

## Benchmark Results

### Dataset Size: $N=20,000$

| Rank | Algorithm Implementation  | Execution Time (ms) | Speed vs. Baseline |
| :--- | :------------------------ | :------------------ | :----------------- |
| 1    | Common merge sort C++     | 3.150               | 118.85x            |
| 2    | Common insertion sort C++ | 32.456              | 11.53x             |
| 3    | Bubble sort quicker ASM   | 107.243             | 3.49x              |
| 4    | Bubble sort quicker C++   | 108.000             | 3.47x              |
| 5    | Common selection sort C++ | 187.020             | 2.00x              |
| 6    | AI Generated Bubble Sort  | 369.737             | 1.01x              |
| 7    | Common bubble sort C++    | 374.358             | Baseline           |
| 8    | Optimized Bubble sort C++ | 378.646             | 0.99x              |
| 9    | Optimized Bubble sort ASM | 523.744             | 0.71x              |

---

_Note: All values are measured in milliseconds. Baseline is the Common Bubble Sort C++ implementation._

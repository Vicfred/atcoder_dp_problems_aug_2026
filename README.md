# AtCoder Educational DP Contest

Solutions and study notes for the [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp).

This repository is primarily for **learning dynamic programming**. The main goal is to preserve clear, intuitive solutions and the reasoning patterns behind them. Optimized or alternative implementations are included when they teach a useful technique, but compactness and micro-optimization are not priorities.

## Goal

This repository is primarily a **learning project**.

The main objective is to understand dynamic programming deeply:

1. Define the DP state precisely.
2. Understand why the base cases are correct.
3. Derive the transition from the meaning of the state.
4. Understand the required evaluation order.
5. Implement the most intuitive version first.
6. Only then study time or memory optimizations.

**Learning and clarity are the top priorities. Performance and memory optimizations are deliberately low priorities unless the constraints require them or the optimization teaches an important reusable idea.**

A simple, readable `O(NK^2)` solution that exposes the recurrence can therefore be more useful while studying than immediately jumping to an optimized `O(NK)` implementation. A correct TLE can still be a useful learning artifact because it separates **correct modeling** from **performance optimization**.

## Progress

**Solved: 22 / 26**

- **A–T:** solved
- **U–W:** pending
- **X–Y:** solved
- **Z:** pending

## Learning rating

The rating is about how useful each problem is as DP study material, not its contest difficulty.

1. **Core — A–M:** foundational DP patterns worth knowing very well.
2. **Important — N–P:** major extensions of the core toolkit.
3. **Useful — Q–T, X, Y:** valuable patterns and combinations of DP with other techniques.
4. **Advanced — U–W, Z:** more specialized or advanced techniques, best studied after the earlier material is comfortable.

## Problems

| # | Problem | Status | Rating | Main idea |
|---:|---|:---:|---|---|
| A | Frog 1 | ✅ | Core | Minimum-cost DP on a sequence. |
| B | Frog 2 | ✅ | Core | Minimum-cost DP with transitions over the previous `K` states. |
| C | Vacation | ✅ | Core | Maximum-value DP with a small state representing the last activity. |
| D | Knapsack 1 | ✅ | Core | Classical 0/1 knapsack by weight; includes memory compression. |
| E | Knapsack 2 | ✅ | Core | State inversion: minimize weight for each attainable value. |
| F | LCS | ✅ | Core | Longest common subsequence DP with reconstruction. |
| G | Longest Path | ✅ | Core | DAG DP after obtaining a topological dependency order. |
| H | Grid 1 | ✅ | Core | Counting paths on a grid with blocked cells. |
| I | Coins | ✅ | Core | Probability DP over the number of heads. |
| J | Sushi | ✅ | Core | Expected-value DP with state compression by counts and first-step analysis. |
| K | Stones | ✅ | Core | Game DP: winning and losing states. |
| L | Deque | ✅ | Core | Interval/game DP for optimal play on both ends of a sequence. |
| M | Candies | ✅ | Core | Counting DP; naive transition, prefix sums, and sliding-window optimization. |
| N | Slimes | ✅ | Important | Interval DP with interval sums; also includes Knuth optimization. |
| O | Matching | ✅ | Important | Bitmask DP for counting perfect matchings. |
| P | Independent Set | ✅ | Important | Tree DP with states for the color of each vertex. |
| Q | Flowers | ✅ | Useful | Weighted LIS DP; quadratic baseline, Fenwick prefix maximum, and segment tree. |
| R | Walk | ✅ | Useful | Counting walks via matrix DP and binary matrix exponentiation. |
| S | Digit Sum | ✅ | Useful | Digit DP with position, remainder, and tightness states. |
| T | Permutation | ✅ | Useful | Rank-based permutation DP; naive cubic transition and prefix/suffix-sum optimization. |
| U | Grouping | ⬜ | Advanced | Subset DP over groups and partitions. |
| V | Subtree | ⬜ | Advanced | Rerooting tree DP. |
| W | Intervals | ⬜ | Advanced | DP combined with interval processing and range data structures. |
| X | Tower | ✅ | Useful | Knapsack-style DP after an exchange argument gives a canonical block order. |
| Y | Grid 2 | ✅ | Useful | Sparse-obstacle grid-path DP using combinatorics and modular binomial coefficients. |
| Z | Frog 3 | ⬜ | Advanced | DP optimization with the convex hull trick. |

## Solution variants

Some problems intentionally keep multiple implementations because comparing them is part of the learning process.

- The normal filename is the main solution, for example `n_slimes.cpp`.
- A trailing `_` before `.cpp` is an alternative or optimized implementation, for example `n_slimes_.cpp`.
- Additional alternatives use more underscores, for example `t_permutation__.cpp`.
- `_TLE` marks an intentionally preserved correct-but-too-slow solution when it helps explain why an optimization is needed.

Notable examples:

- **D — Knapsack 1:** full 2D DP and memory-compressed 1D DP.
- **E — Knapsack 2:** value-based knapsack variants.
- **G — Longest Path:** different topological approaches.
- **I — Coins:** full and memory-compressed probability DP.
- **M — Candies:** naive TLE, prefix sums, sliding windows, and in-place variants.
- **N — Slimes:** classical `O(N^3)` interval DP and Knuth-optimized `O(N^2)` DP.
- **O — Matching:** reverse/predecessor and forward bitmask formulations.
- **Q — Flowers:** `O(N^2)` weighted-LIS baseline, Fenwick tree, and segment tree implementations.
- **T — Permutation:** `O(N^3)` baseline, prefix-sum optimization, rolling rows, and in-place prefix/suffix sums.
- **X — Tower:** full 2D knapsack DP and memory-compressed 1D DP.

## Philosophy

The repository deliberately keeps intuitive intermediate solutions when they expose the recurrence better than the optimized version. A correct TLE can be useful study material when it makes the bottleneck obvious and shows exactly what the later optimization improves.

The recurring progression is:

1. define a precise DP state;
2. derive the recurrence and base cases;
3. implement the clearest correct version;
4. identify the actual bottleneck from the constraints;
5. optimize only the expensive part while preserving the original reasoning when possible.

That progression is often more valuable than memorizing the final trick in isolation.

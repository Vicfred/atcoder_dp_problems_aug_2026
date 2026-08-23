i# AtCoder Educational DP Contest

Solutions and study notes for the [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp/tasks).

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

The problems **A through M** have been completed so far. Their ratings below reflect how broadly useful each problem is for learning dynamic programming.

## Importance Rating

The stars measure how valuable I consider each problem for **learning dynamic programming**, not how difficult or prestigious the technique is.

| Rating | Meaning |
|---|---|
| ★★★★★ | Core DP pattern with very broad learning value |
| ★★★★☆ | Highly useful and broadly reusable |
| ★★★☆☆ | Useful, but less central or somewhat specialized |
| ★★☆☆☆ | More specialized, situational, or optimization-heavy |
| ★☆☆☆☆ | Very specialized; useful mainly after the fundamentals are strong |

### Rating Philosophy

This ranking is intentionally selective.

Not every interesting DP technique deserves the same learning priority. Core state-design patterns, knapsack, LCS, grid DP, DAG DP, interval DP, and basic tree/bitmask DP have broader educational value than specialized optimizations such as convex hull trick or lazy-segment-tree DP.

A `★☆☆☆☆` problem is **not a bad problem**. It means the technique is comparatively specialized and is usually more useful after the fundamental DP patterns are comfortable.

Likewise, `★★☆☆☆` means the problem is worth studying, but its main technique is less universal than the higher-rated patterns.


## Problem Roadmap

| # | Problem | Status | DP type | Main idea / lesson | Importance |
|---:|---|---|---|---|:---:|
| 1 | [A - Frog 1](https://atcoder.jp/contests/dp/tasks/dp_a) | ✅ Solved | Minimum-cost DP | `dp[i]` is the minimum cost to reach stone `i`; transition from the previous one or two stones. A clean introduction to defining a state as an optimal value. | ★★★★★ |
| 2 | [B - Frog 2](https://atcoder.jp/contests/dp/tasks/dp_b) | ✅ Solved | Minimum-cost DP | Generalizes Frog 1 so each state considers the previous `K` stones. Good practice for transitions that take a minimum over many predecessors. | ★★★★★ |
| 3 | [C - Vacation](https://atcoder.jp/contests/dp/tasks/dp_c) | ✅ Solved | Maximum-value DP | Track the best happiness while remembering which activity was chosen last. Excellent lesson in making every stored value satisfy the semantic meaning of its state. | ★★★★★ |
| 4 | [D - Knapsack 1](https://atcoder.jp/contests/dp/tasks/dp_d) | ✅ Solved | 0/1 knapsack | Classical weight-indexed 0/1 knapsack. Important for understanding take/skip transitions and why one-dimensional compression requires iterating capacities backward. | ★★★★★ |
| 5 | [E - Knapsack 2](https://atcoder.jp/contests/dp/tasks/dp_e) | ✅ Solved | Value-based 0/1 knapsack | When the obvious DP dimension is too large, change the state: store the minimum weight needed to obtain each total value. A major state-design lesson. | ★★★★☆ |
| 6 | [F - LCS](https://atcoder.jp/contests/dp/tasks/dp_f) | ✅ Solved | Longest common subsequence | Classical two-sequence DP together with reconstruction. Teaches prefix states and recovering an actual optimal solution from a DP table. | ★★★★★ |
| 7 | [G - Longest Path](https://atcoder.jp/contests/dp/tasks/dp_g) | ✅ Solved | DAG DP | Longest path in a DAG using topological order. The main lesson is that DP requires a valid dependency order, not merely a recurrence. | ★★★★☆ |
| 8 | [H - Grid 1](https://atcoder.jp/contests/dp/tasks/dp_h) | ✅ Solved | Grid counting DP | Count paths to each free cell from above and left. A canonical grid DP and a clean example of rolling-array memory compression. | ★★★★★ |
| 9 | [I - Coins](https://atcoder.jp/contests/dp/tasks/dp_i) | ✅ Solved | Probability DP | `dp[i][h]` stores the probability of exactly `h` heads after the first `i` coins. Good introduction to storing an entire probability distribution in DP. | ★★★☆☆ |
| 10 | [J - Sushi](https://atcoder.jp/contests/dp/tasks/dp_j) | ✅ Solved | Expectation DP / probability DP | Expected remaining time from a compressed state `(a,b,c)`. Introduces first-step analysis, conditional expectation, geometric waiting time, absorbing states, and self-loop equations. | ★★☆☆☆ |
| 11 | [K - Stones](https://atcoder.jp/contests/dp/tasks/dp_k) | ✅ Solved | Game DP | A state is winning exactly when there exists a legal move to a losing state for the opponent. A compact introduction to winning/losing state DP. | ★★★☆☆ |
| 12 | [L - Deque](https://atcoder.jp/contests/dp/tasks/dp_l) | ✅ Solved | Interval DP / game DP | Solve smaller intervals before larger ones while both players act optimally. The current implementation stores the best total score obtainable from an interval and uses prefix sums for the remaining total. | ★★★★☆ |
| 13 | [M - Candies](https://atcoder.jp/contests/dp/tasks/dp_m) | ✅ Solved | Counting DP with prefix sums / sliding window | Start from the intuitive bounded counting recurrence, observe that every transition is a contiguous range sum, then reduce the time complexity with prefix sums or a sliding window. | ★★★★☆ |
| 14 | [N - Slimes](https://atcoder.jp/contests/dp/tasks/dp_n) | ⬜ Pending | Interval DP | Classical interval merging DP. Choose the final split of an interval and combine solutions for its two subintervals. One of the most important interval-DP exercises. | ★★★★★ |
| 15 | [O - Matching](https://atcoder.jp/contests/dp/tasks/dp_o) | ⬜ Pending | Bitmask DP | Use a subset mask to record which partners have already been matched. A canonical introduction to DP where the state is a subset. | ★★★★☆ |
| 16 | [P - Independent Set](https://atcoder.jp/contests/dp/tasks/dp_p) | ⬜ Pending | Tree DP | For each tree node, track possibilities depending on whether the node is selected. A fundamental example of combining child states on trees. | ★★★★☆ |
| 17 | [Q - Flowers](https://atcoder.jp/contests/dp/tasks/dp_q) | ⬜ Pending | Maximum-value DP + segment tree | A weighted increasing-subsequence style DP whose transition needs a fast maximum over a height range. Valuable for learning how data structures optimize DP transitions. | ★★★☆☆ |
| 18 | [R - Walk](https://atcoder.jp/contests/dp/tasks/dp_r) | ⬜ Pending | Matrix DP / matrix exponentiation | Count walks of a fixed length using powers of the adjacency matrix. Important connection between linear recurrences, DP transitions, and matrix exponentiation. | ★★☆☆☆ |
| 19 | [S - Digit Sum](https://atcoder.jp/contests/dp/tasks/dp_s) | ⬜ Pending | Digit DP | Count integers under an upper bound while tracking prefix restrictions and digit-sum information. Digit DP is a highly reusable state-design pattern. | ★★★☆☆ |
| 20 | [T - Permutation](https://atcoder.jp/contests/dp/tasks/dp_t) | ⬜ Pending | Counting DP with prefix sums | Count permutations satisfying chains of inequalities. The core recurrence is optimized using prefix sums, making it a good second encounter with prefix-sum DP optimization. | ★★☆☆☆ |
| 21 | [U - Grouping](https://atcoder.jp/contests/dp/tasks/dp_u) | ⬜ Pending | Subset DP | Partition elements into groups while maximizing total score. Strong practice with subset states and enumerating submasks. | ★★☆☆☆ |
| 22 | [V - Subtree](https://atcoder.jp/contests/dp/tasks/dp_v) | ⬜ Pending | Rerooting tree DP | Compute an answer for every possible root by reusing information across adjacent roots. Rerooting is a major advanced tree-DP pattern. | ★★☆☆☆ |
| 23 | [W - Intervals](https://atcoder.jp/contests/dp/tasks/dp_w) | ⬜ Pending | DP optimization + lazy segment tree | An optimization-heavy DP where range updates and range maxima are maintained with a lazy segment tree. Useful, but more specialized than the core DP patterns. | ★☆☆☆☆ |
| 24 | [X - Tower](https://atcoder.jp/contests/dp/tasks/dp_x) | ⬜ Pending | Knapsack-style maximum-value DP | Sort blocks into a valid order and then use a knapsack-like DP over total weight. Good practice combining a structural observation with a familiar DP. | ★★☆☆☆ |
| 25 | [Y - Grid 2](https://atcoder.jp/contests/dp/tasks/dp_y) | ⬜ Pending | Combinatorial grid DP | Count monotone paths on a huge grid by combining combinatorics with DP over obstacles rather than storing every grid cell. | ★★☆☆☆ |
| 26 | [Z - Frog 3](https://atcoder.jp/contests/dp/tasks/dp_z) | ⬜ Pending | Minimum-cost DP + convex hull trick | Starts from a simple quadratic minimum-cost recurrence and optimizes it with the convex hull trick. Excellent optimization study, but more specialized than the core DP patterns. | ★☆☆☆☆ |

## Completed Problems: A-M

### A - Frog 1

**Type:** Minimum-cost DP

State:

```text
dp[i] = minimum cost required to reach stone i
```

The transition considers jumping from stone `i - 1` or `i - 2`.

Main lesson: define a state as the optimal value for a prefix and derive each predecessor directly from the allowed moves.

### B - Frog 2

**Type:** Minimum-cost DP

Generalizes Frog 1:

```text
dp[i] = minimum cost required to reach stone i
```

but now every state considers up to `K` previous stones.

Main lesson: a DP transition can be a minimum over a variable set of predecessors.

### C - Vacation

**Type:** Maximum-value DP

State:

```text
dp[i][a] = maximum happiness through day i
           if activity a is chosen on day i
```

Main lesson: every stored value must actually satisfy the semantic meaning assigned to its state.

### D - Knapsack 1

**Type:** 0/1 knapsack

The intuitive state is:

```text
dp[i][w] = maximum value obtainable using the first i items
           with capacity at most w
```

The repository also contains a one-dimensional version.

Main lesson: when compressing 0/1 knapsack, iterate capacities backward so the current item cannot be reused.

### E - Knapsack 2

**Type:** Value-based 0/1 knapsack

Instead of indexing by weight:

```text
dp[v] = minimum weight needed to obtain exactly value v
```

Main lesson: when the obvious state dimension is too large, search for another bounded quantity that can parameterize the states.

### F - LCS

**Type:** Longest common subsequence

State:

```text
dp[i][j] = LCS length of the first i characters of s
           and the first j characters of t
```

The full table also supports reconstruction of an actual longest common subsequence.

Main lesson: some DP tables contain enough information to recover an optimal object, not only its value.

### G - Longest Path

**Type:** DAG DP

State:

```text
dp[v] = length of the longest directed path ending at v
```

The repository contains implementations using both Kahn's algorithm and DFS topological sorting.

Main lesson: a recurrence is not enough. DP states must be evaluated only after their dependencies are ready.

### H - Grid 1

**Type:** Grid counting DP

State:

```text
dp[i][j] = number of paths from (0, 0) to (i, j)
```

A free cell receives paths from above and from the left. Obstacles contribute zero.

Main lesson: canonical grid DP and a natural introduction to rolling-array memory optimization.

### I - Coins

**Type:** Probability DP

State:

```text
dp[i][h] = probability of obtaining exactly h heads
           after tossing the first i coins
```

The repository contains both the full two-dimensional version and a memory-compressed version.

Main lesson: a DP table can store a probability distribution instead of counts, minima, or maxima.

### J - Sushi

**Type:** Expectation DP / probability DP

State:

```text
E[a][b][c] = expected number of additional rolls
             when a dishes have 1 sushi,
                  b dishes have 2 sushi,
                  c dishes have 3 sushi
```

Main probability lessons:

- expected value
- conditional expectation
- law of total expectation
- first-step analysis
- geometric waiting time
- self-loops
- absorbing states

This problem is intentionally treated as a probability tutorial rather than merely a recurrence to memorize.

### K - Stones

**Type:** Game DP

State:

```text
dp[k] = whether the player whose turn it is can force a win
        with k stones remaining
```

The central rule is:

```text
winning state <=> there exists a move to a losing state
```

Main lesson: game DP is often naturally expressed in terms of the player whose turn it is rather than a fixed player.

### L - Deque

**Type:** Interval DP / game DP

The current solution stores:

```text
dp[l][r] = maximum total score the player whose turn it is
           can obtain from interval [l, r]
```

Smaller intervals are solved before larger intervals.

Prefix sums provide the total value remaining after taking the left or right endpoint.

Main lesson: interval DP usually depends on strictly smaller intervals, so interval length provides a natural evaluation order.

### M - Candies

**Type:** Counting DP with prefix sums / sliding window

The intuitive recurrence is:

```text
dp[i][k] = number of ways to distribute exactly k candies
           among the first i children
```

For child `i`, try every legal number `x` of candies:

```text
dp[i][k] += dp[i - 1][k - x]
```

This straightforward version is intentionally preserved as `m_candies_TLE.cpp`.

The important optimization comes afterward: the transition is a sum over a contiguous range of the previous DP row. Prefix sums or a sliding window reduce the time complexity from roughly `O(NK^2)` to `O(NK)`.

Main lesson:

```text
Understand the expensive recurrence first.
Then optimize the repeated work.
```

This is exactly the learning philosophy of the repository.

## Repository Notes

Some problems intentionally have multiple implementations.

The main solution keeps the normal problem filename, for example:

```text
d_knapsack_1.cpp
```

**Alternative solutions or optimized versions are named by adding a trailing `_` before the file extension**, for example:

```text
d_knapsack_1_.cpp
i_coins_.cpp
```

If a problem has several alternative implementations, additional trailing underscores distinguish them:

```text
m_candies.cpp
m_candies_.cpp
m_candies__.cpp
m_candies___.cpp
```

A descriptive suffix may also be used when the purpose of a version is especially important to preserve, such as:

```text
m_candies_TLE.cpp
```

The point is not to keep only the shortest or fastest solution. Alternative versions preserve useful stages of the learning process, such as:

- intuitive full DP tables
- memory-compressed DP
- different topological-sort strategies
- prefix-sum optimization
- sliding-window optimization
- deliberately naive solutions that demonstrate why an optimization is necessary

In particular, `m_candies_TLE.cpp` is intentionally useful: it represents the correct intuitive counting DP before the prefix-sum/sliding-window optimization.

## Current Progress

```text
A  Frog 1          ✅
B  Frog 2          ✅
C  Vacation        ✅
D  Knapsack 1      ✅
E  Knapsack 2      ✅
F  LCS             ✅
G  Longest Path    ✅
H  Grid 1          ✅
I  Coins           ✅
J  Sushi           ✅
K  Stones          ✅
L  Deque           ✅
M  Candies         ✅
N  Slimes          ⬜
O  Matching        ⬜
P  Independent Set ⬜
Q  Flowers         ⬜
R  Walk            ⬜
S  Digit Sum       ⬜
T  Permutation     ⬜
U  Grouping        ⬜
V  Subtree         ⬜
W  Intervals       ⬜
X  Tower           ⬜
Y  Grid 2          ⬜
Z  Frog 3          ⬜
```

Next problem:

**N - Slimes**

🐈

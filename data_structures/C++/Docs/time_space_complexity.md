# Time & Space Complexity

How to reason about how *fast* and how *memory-hungry* an algorithm is — building up from counting iterations to Big-O.

## Table of Contents
1. [Sum of First N Natural Numbers](#1-sum-of-first-n-natural-numbers)
2. [Count Elements in a Range](#2-count-elements-in-a-range)
3. [Counting Factors (naïve O(N))](#3-counting-factors-naïve-on)
4. [Iterations, Time Limits & Verdicts](#4-iterations-time-limits--verdicts)
5. [Optimising Factors to O(√N)](#5-optimising-factors-to-o√n)
6. [Counting Iterations of Loops](#6-counting-iterations-of-loops)
7. [Why Execution Time Is a Bad Metric](#7-why-execution-time-is-a-bad-metric)
8. [Big-O Time Complexity](#8-big-o-time-complexity)
9. [Complexity Ordering (cheat sheet)](#9-complexity-ordering-cheat-sheet)

---

## 1. Sum of First N Natural Numbers

```
N = 5    → 1 + 2 + 3 + 4 + 5        = 15
N = 100  → 1 + 2 + … + 100          = 5050
N = 1000 → 1 + 2 + … + 1000         = 505000
```

**Gauss's trick** — write the sum forwards and backwards, then add:

```
 S =   1  +   2  +   3  + … +  100
 S = 100  +  99  +  98  + … +    1
-----------------------------------
2S = 101  + 101  + 101  + … + 101      (100 terms)
2S = 101 × 100
 S = (101 × 100) / 2 = 101 × 50 = 5050
```

Generalised:

```
 S = 1 + 2 + 3 + … + N
2S = (N+1) × N
```

$$\boxed{S = \dfrac{N(N+1)}{2}}$$

**Partial sums by subtraction** — e.g. sum from 9 to 100:

$$9 + 10 + \dots + 100 = \underbrace{(1 + 2 + \dots + 100)}_{\frac{100 \times 101}{2}} - \underbrace{(1 + 2 + \dots + 8)}_{\frac{8 \times 9}{2}}$$

---

## 2. Count Elements in a Range

How many integers are in a consecutive sequence `L, L+1, …, R`?

```
3, 4, 5, 6, 7, 8   →  8 - 3 + 1 = 6 terms
```

$$\boxed{[L, R] \Rightarrow R - L + 1}$$

**Inclusion vs exclusion** — `[ ]` includes the endpoint, `( )` excludes it:

| Range | Elements (for `[3,8]`) | Count |
|-------|------------------------|-------|
| `[L, R]` | 3, 4, 5, 6, 7, 8 | `R - L + 1` |
| `[L, R)` | 3, 4, 5, 6, 7 | `R - L` |
| `(L, R]` | 4, 5, 6, 7, 8 | `R - L` |
| `(L, R)` | 4, 5, 6, 7 | `R - L - 1` |

---

## 3. Counting Factors (naïve O(N))

A **factor** of `N` divides it exactly (`N % i == 0`).

```
12 → 1, 2, 3, 4, 6, 12   ⇒ 6 factors
15 → 1, 3, 5, 15         ⇒ 4 factors
```

- **Min factor** of any `N` = `1`; **Max factor** = `N`.

```cpp
int count = 0;
for (int i = 1; i <= N; i++)
{
    if (N % i == 0)   // i is a factor of N
    {
        count++;
    }
}
cout << count;
```

This loop runs **N iterations** → **O(N)**.

---

## 4. Iterations, Time Limits & Verdicts

**# iterations = how many times the loop runs.** On a judge (e.g. Codeforces) each problem has a **time limit (typically 1 sec)**. After you submit, possible verdicts:

- **Accepted** ✅
- **Wrong Answer**
- **Time Limit Exceeded (TLE)** — code takes too long to execute
- **Runtime Error** — e.g. accessing `Arr[100]` when `Arr` has size 10 (out of bounds)

**Standard assumption:** a computer does about **10⁸ iterations per second**.

```
1  sec →  10⁸  iterations
2  sec →  2 × 10⁸ iterations
10 sec →  10⁹  iterations
```

| N (= #iterations) | Time | |
|---|---|---|
| 10⁸  | 1 sec | |
| 10⁹  | 10 sec | (10⁹ / 10⁸) |
| 10¹² | 10⁴ sec ≈ 10,000 sec | (10¹² / 10⁸) |
| 10¹⁸ | 10¹⁰ sec ≈ **300+ years** | → **TLE** |

> 10¹⁰ seconds is not minutes/hours/days — it's **hundreds of years**. An O(N) scan over 10¹⁸ is hopeless; we need a better algorithm.

---

## 5. Optimising Factors to O(√N)

**Key insight — factors come in pairs.** If `i` divides `N`, then so does `j = N / i`, and `i × j = N`.

```
12 → (1,12) (2,6) (3,4)
18 → (1,18) (2,9) (3,6)
36 → (1,36) (2,18) (3,12) (4,9) (6,6)
```

```
12
---------
i     N/i
1  <  12
2  <  6
3  <  4
---------
4  >  3
6  >  2
12 >  1

i ≤ N/i

```

So we only need to loop `i` while `i ≤ N/i`. Since:

$$i \le \frac{N}{i} \;\Rightarrow\; i^2 \le N \;\Rightarrow\; \boxed{i \le \sqrt{N}}$$

we iterate `i` from `1` to `√N` and add **2 factors per pair** (`i` and `N/i`).

**Perfect squares** (e.g. `N = 36`, where `6 × 6 = 36`): when `i == N/i` the two factors are the same, so add **1**, not 2.

```cpp
int count = 0;
for (int i = 1; i <= sqrt(N); i++)
{
    if (N % i == 0)
    {
        int j = N / i;
        if (i == j)
        {
            count++;       // perfect-square middle factor, counted once
        }
        else
        {
            count += 2;    // the pair (i, N/i)
        }
    }
}
cout << count;
```

This is **O(√N)** — dramatically faster. Compare the two approaches:

| N | O(N) iterations | O(√N) iterations | O(√N) time |
|---|---|---|---|
| 10⁸  | 10⁸  | 10⁴ | < 1 sec |
| 10¹² | 10¹² (TLE) | 10⁶ | < 1 sec |
| 10¹⁶ | — | 10⁸ | 1 sec |
| 10¹⁸ | — | 10⁹ | 10 sec |

> A better **algorithm** turns "300+ years" into "10 seconds" — far more powerful than a faster computer.

---

## 6. Counting Iterations of Loops

**Linear loops → N iterations:**

```cpp
for (int i = 1; i <= N; i++) { … }   // N iterations
for (int i = N; i >= 1; i--) { … }   // N iterations
for (int i = 1; i <= N; i--) { … }   // ❌ INFINITE (i only decreases, condition never fails for N > 0)
```

**Halving / doubling loops → log₂N iterations:**

```cpp
int i = N;
while (i > 1)
{
    i = i / 2;
}
// N = 16 → 4 steps (16→8→4→2→1) ( 2^4 = 16 )
// N = 32 → 5 steps ( 2^5 = 32 )
// N = 4096 → 12 steps ( 2^12 = 4096 )
```

Why? After `k` halvings we reach 1: `2^k = N ⇒ k = log₂N`. It is **not** `N` and **not** `√N` — it's `log₂N`.

```cpp
int i = 1;
while (i < N) { i = i * 2; }   // log₂N iterations  (1→2→4→8→16)

int i = 0;
while (i <= N) { i = i * 2; }  // ❌ INFINITE (0 * 2 = 0, i never grows)
```

```cpp
int i = 1;
while (i < N) { i = i * 3; }   // log3N iterations  (1→3→9→27)
```

**Nested loops:**

```cpp
// full N×N → N² iterations → O(N²)
for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
        print(i + j);


i   j       total iterations
-----------------------------
1   1 - N   N
2   1 - N   N
.
.
N   1 - N   N 
-----------------------------
            N * N = N^2
```

```cpp
// triangular: inner runs i times → 1 + 2 + … + N
for (int i = 1; i <= N; i++)
    for (int j = 1; j <= i; j++)
        print(i + j);
// = N(N+1)/2 → still O(N²)

i   j       total iterations
-----------------------------
1   1 - 1   1
2   1 - 2   2
3   1 - 3   3
.
.
N   1 - N   N 
-----------------------------
sum of N natural numbers = N(N*1) / 2
```

---

## 7. Why Execution Time Is a Bad Metric

The same algorithm ("sort an array") clocks different wall-times depending on **external factors** — hardware, OS, and programming language:

```
Idea 1:  12 s (Windows XP) → 8 s (Rust) → 6 s (fast machine)
Idea 2:  10 s (macOS)      → 6 s (Rust)
```

> **Execution time is NOT a good parameter** to compare two ideas/algorithms.
> **# iterations is a better parameter** — it's independent of the machine.

---

## 8. Big-O Time Complexity

Big-O expresses the **growth** of the iteration count as `N` grows, ignoring machine-specific constants. Three steps:

1. **Find the # of iterations** (as a formula in `N`).
2. **Ignore / remove all constants.**
3. **Remove all lower-order (lower-contribution) terms.**

**Example 1**

```
10N² + 8N + 600
  → drop constants:   N² + N   (and the standalone 600)
  → drop lower term:  N²
  ⇒ O(N²)
```

**Example 2**

```
N³ + 7N + N³·logN + N²·√N
  → dominant term is N³·logN
  ⇒ O(N³·logN)
```

**Example 3 — constant work**

```cpp
for (int i = 1; i <= 100; i++) { … }   // runs 100 times, independent of N
⇒ O(1)
```

A fixed number of steps that doesn't depend on `N` is **O(1)** (constant time).

---

## 9. Complexity Ordering (cheat sheet)

From fastest (best) to slowest (worst):

$$O(1) < O(\log N) < O(\sqrt{N}) < O(N) < O(N\log N) < O(N\sqrt{N}) < O(N^2) < O(2^N) < O(N!)$$

| Big-O | Name | Example |
|-------|------|---------|
| `O(1)` | constant | fixed number of steps |
| `O(log N)` | logarithmic | binary search, halving loop |
| `O(√N)` | root | counting factors (optimised) |
| `O(N)` | linear | single pass over an array |
| `O(N log N)` | linearithmic | good sorting algorithms |
| `O(N√N)` | — | |
| `O(N²)` | quadratic | nested loops / bubble, selection sort |
| `O(2^N)` | exponential | subsets |
| `O(N!)` | factorial | permutations |

> Every algorithm is analysed on two axes: **Time Complexity (TC)** and **Space Complexity (SC)**.

--- 

## Time Complexity

1. Find the # of iterations in terms of input size (N)
2. Remove the constants
3. Remove the lower contribution terms

**Examples:**

1. `5N² + 2N + 10` → `O(N²)`
2. `11N³ + 12N² + 13N + 17000` → `O(N³)`

### Loop analysis examples

**1)**
```c
for (i = 1; i <= N; i++)
{
    ...
}
```
→ `O(N)` (assuming `N > 0`)

**2)**
```c
for (i = 1; i <= N; i--)
{
    ...
}
```
→ `O(∞)` — Infinite loop

**3)**
```c
for (i = 1; i <= N; i *= 2)
{
    ...
}
```
→ `O(log N)` — sequence: 1 → 2 → 4 → 8 → 16 → 32 → 64 ...

**4) Nested loop**
```c
for (i = 1; i <= N; i++)
{
    for (j = 1; j <= i; j++)
    {
        ...
    }
}
```

Table of iterations of inner loop `#itr` per `i`:

| i | j range | #itr |
|---|---|---|
| 1 | 1–1 | 1 |
| 2 | 1–2 | 2 |
| 3 | 1–3 | 3 |
| 4 | 1–4 | 4 |
| ... | ... | ... |
| N | 1–N | N |

Total = `N(N+1)/2 = N²/2 + N/2` → `O(N²)`

---

## Importance of Constraints

Which complexities are feasible depends on N (assuming ~10⁷–10⁸ operations per second):

| Constraint | O(N³) | O(N²) | O(N√N) | O(N) | O(√N) | O(log N) | O(1) |
|---|---|---|---|---|---|---|---|
| N ≤ 10¹⁸ | ✗ | ✗ | ✗ | ✗ | ✗ | ✓ | ✓ |
| N ≤ 10⁹ | ✗ | ✗ | ✗ | ✗ (borderline) | ✓ | ✓ | ✓ |
| N ≤ 10⁷ | ✗ | ✗ | ✗ | ✓ | ✓ | ✓ | ✓ |
| N ≤ 10⁵ | ✗ | ✗ | ✓ | ✓ | ✓ | ✓ | ✓ |
| N ≤ 10⁴ | ✗ | ✓ (maybe) | ✓ | ✓ | ✓ | ✓ | ✓ |
| N ≤ 10³ | ✗ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| N ≤ 10² | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |

Rule of thumb: ~10⁷–10⁸ iterations run in about 1 second.

---

## Space Complexity

1. Find the **MAX SPACE UTILISED AT ANY POINT** in terms of input size (N)
2. Remove the constants
3. Remove the lower contribution terms

Example: variables of sizes 3 + 2 + 1 + 4 + 2 = 12 MB (not 4 MB — take the sum/max utilized at any point in time, not just one variable).

Space usage over time can rise and fall (graph of space vs. time) — space complexity considers the maximum point reached.

### Rule of thumb
- **Loop → Time Complexity (TC)**
- **Array → Space Complexity (SC)**

```c
int A[N];
for (i = 0; i < N; i++)
{
    ...
}
```
→ TC: `O(N)`, SC: `O(N)`

```c
int A[N][M];
for (i = 0; i < N; i++)
{
    for (j = 0; j < M; j++)
    {
        ...
    }
}
```
→ TC: `O(N*M)`, SC: `O(N*M)`

**Note:** If the array is declared *inside* the outer loop (reallocated each iteration and not retained), the space complexity can drop:
```c
for (i = 0; i < N; i++)
{
    int A[N];
    for (j = 0; j < M; j++)
    {
        ...
    }
}
```
→ TC: `O(N*M)`, **SC: `O(N)`** (array is reused/discarded per outer iteration, not accumulated as N×M)


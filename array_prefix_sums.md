# Array Techniques

---

## Range Sum Query

Given array:
```
A = [7, 1, 5, -3, 2, 10, 5, 8]
     0  1  2   3  4   5  6  7
```

Query `(L, R)` → `A[L] + A[L+1] + ... + A[R]`

Constraints: `1 ≤ N ≤ 10⁵`, `1 ≤ Q ≤ 10⁵`

Example queries:
- `(1, 3)` → `A[1] + A[2] + A[3] = 3`
- `(0, 4)` → `A[0] + A[1] + A[2] + A[3] + A[4] = 12`
- `(5, 6)` → `A[5] + A[6] = 15`

### Naive approach

```c
int N;
cin >> N;
int A[N];
for (i = 0; i < N; i++)
{
    cin >> A[i];
}

int Q;
cin >> Q;
for (i = 0; i < Q; i++)
{
    int L, R;
    cin >> L >> R;

    sum = 0;
    for (j = L; j <= R; j++)
    {
        sum += A[j];
    }
    print(sum);
}
```

Time Complexity: `O(Q*N + N)` ≈ `O(Q*N)`. With `Q, N ~ 10⁵`, this gives `10⁵ × 10⁵ = 10¹⁰` → **TLE (Time Limit Exceeded)**.

Space Complexity: `O(1)` (excluding input storage).

### Prefix Sum approach

Build a prefix sum array `P` such that:
```
P[i] = A[0] + A[1] + A[2] + ... + A[i]
```

Example:
```
A = [7,  1,  5, -3,  2, 10,  5,  8]
     0   1   2   3   4   5   6   7

P = [7,  8, 13, 10, 12, 22, 27, 35]
     0   1   2   3   4   5   6   7
```

Sample lookups:
- `(0, 5) → 22`
- `(0, 3) → 10`
- `(0, 7) → 35`
- `(2, 6) → P[6] - P[1] = 27 - 8 = 19`

**Derivation:**
```
---

## Range Sum Query

Given array:
```
A = [7, 1, 5, -3, 2, 10, 5, 8]
     0  1  2   3  4   5  6  7
```

Query `(L, R)` → `A[L] + A[L+1] + ... + A[R]`

Constraints: `1 ≤ N ≤ 10⁵`, `1 ≤ Q ≤ 10⁵`

Example queries:
- `(1, 3)` → `A[1] + A[2] + A[3] = 3`
- `(0, 4)` → `A[0] + A[1] + A[2] + A[3] + A[4] = 12`
- `(5, 6)` → `A[5] + A[6] = 15`

### Naive approach

```c
int N;
cin >> N;
int A[N];
for (i = 0; i < N; i++)
{
    cin >> A[i];
}

int Q;
cin >> Q;
for (i = 0; i < Q; i++)
{
    int L, R;
    cin >> L >> R;

    sum = 0;
    for (j = L; j <= R; j++)
    {
        sum += A[j];
    }
    print(sum);
}
```

Time Complexity: `O(Q*N + N)` ≈ `O(Q*N)`. With `Q, N ~ 10⁵`, this gives `10⁵ × 10⁵ = 10¹⁰` → **TLE (Time Limit Exceeded)**.

Space Complexity: `O(1)` (excluding input storage).

### Prefix Sum approach

Build a prefix sum array `P` such that:
```
P[i] = A[0] + A[1] + A[2] + ... + A[i]
```

Example:
```
A = [7,  1,  5, -3,  2, 10,  5,  8]
     0   1   2   3   4   5   6   7

P = [7,  8, 13, 10, 12, 22, 27, 35]
     0   1   2   3   4   5   6   7
```

Sample lookups:
- `(0, 5) → 22`
- `(0, 3) → 10`
- `(0, 7) → 35`
- `(2, 6) → P[6] - P[1] = 27 - 8 = 19`

**Derivation:**
```
P[R] = A[0] + A[1] + ... + A[L-1] + A[L] + A[L+1] + ... + A[R]
P[R] = (A[0] + A[1] + ... + A[L-1]) + (A[L] + A[L+1] + ... + A[R])
P[R] = P[L-1] + ans
```

So:
```
ans = P[R] - P[L-1]
```

**Formula:**
```
Sum(L, R) = P[R]              if L == 0
          = P[R] - P[L-1]     if L != 0
```

(Valid for `1 ≤ L ≤ R ≤ N` in 1-indexed terms, or `0 ≤ L ≤ R ≤ N-1` in 0-indexed terms.)

### Building the prefix sum array

```c
int N;
cin >> N;
int A[N];
for (i = 0; i < N; i++)
{
    cin >> A[i];
}

int P[N];
sum = 0;
for (i = 0; i < N; i++)
{
    sum += A[i];
    P[i] = sum;
}   // Building the Prefix Sum array
```

### Answering queries using prefix sum

```c
int Q;
cin >> Q;
for (i = 0; i < Q; i++)
{
    int L, R;
    cin >> L >> R;

    if (L == 0)
    {
        print(P[R]);
    }
    else
    {
        print(P[R] - P[L-1]);
    }

P[R] = A[0] + A[1] + ... + A[L-1] + A[L] + A[L+1] + ... + A[R]
P[R] = (A[0] + A[1] + ... + A[L-1]) + (A[L] + A[L+1] + ... + A[R])
P[R] = P[L-1] + ans
```

So:
```
ans = P[R] - P[L-1]
```

**Formula:**
```
Sum(L, R) = P[R]              if L == 0
          = P[R] - P[L-1]     if L != 0
```

(Valid for `1 ≤ L ≤ R ≤ N` in 1-indexed terms, or `0 ≤ L ≤ R ≤ N-1` in 0-indexed terms.)

### Building the prefix sum array

```c
int N;
cin >> N;
int A[N];
for (i = 0; i < N; i++)
{
    cin >> A[i];
}

int P[N];
sum = 0;
for (i = 0; i < N; i++)
{
    sum += A[i];
    P[i] = sum;
}   // Building the Prefix Sum array
```

### Answering queries using prefix sum

```c
int Q;
cin >> Q;
for (i = 0; i < Q; i++)
{
    int L, R;
    cin >> L >> R;

---

## Range Sum Query

Given array:
```
A = [7, 1, 5, -3, 2, 10, 5, 8]
     0  1  2   3  4   5  6  7
```

Query `(L, R)` → `A[L] + A[L+1] + ... + A[R]`

Constraints: `1 ≤ N ≤ 10⁵`, `1 ≤ Q ≤ 10⁵`

Example queries:
- `(1, 3)` → `A[1] + A[2] + A[3] = 3`
- `(0, 4)` → `A[0] + A[1] + A[2] + A[3] + A[4] = 12`
- `(5, 6)` → `A[5] + A[6] = 15`

### Naive approach

```c
int N;
cin >> N;
int A[N];
for (i = 0; i < N; i++)
{
    cin >> A[i];
}

int Q;
cin >> Q;
for (i = 0; i < Q; i++)
{
    int L, R;
    cin >> L >> R;

    sum = 0;
    for (j = L; j <= R; j++)
    {
        sum += A[j];
    }
    print(sum);
}
```

Time Complexity: `O(Q*N + N)` ≈ `O(Q*N)`. With `Q, N ~ 10⁵`, this gives `10⁵ × 10⁵ = 10¹⁰` → **TLE (Time Limit Exceeded)**.

Space Complexity: `O(1)` (excluding input storage).

### Prefix Sum approach

Build a prefix sum array `P` such that:
```
P[i] = A[0] + A[1] + A[2] + ... + A[i]
```

Example:
```
A = [7,  1,  5, -3,  2, 10,  5,  8]
     0   1   2   3   4   5   6   7

P = [7,  8, 13, 10, 12, 22, 27, 35]
     0   1   2   3   4   5   6   7
```

Sample lookups:
- `(0, 5) → 22`
- `(0, 3) → 10`
- `(0, 7) → 35`
- `(2, 6) → P[6] - P[1] = 27 - 8 = 19`

**Derivation:**
```
P[R] = A[0] + A[1] + ... + A[L-1] + A[L] + A[L+1] + ... + A[R]
P[R] = (A[0] + A[1] + ... + A[L-1]) + (A[L] + A[L+1] + ... + A[R])
P[R] = P[L-1] + ans
```

So:
```
ans = P[R] - P[L-1]
```

**Formula:**
```
Sum(L, R) = P[R]              if L == 0
          = P[R] - P[L-1]     if L != 0
```

(Valid for `1 ≤ L ≤ R ≤ N` in 1-indexed terms, or `0 ≤ L ≤ R ≤ N-1` in 0-indexed terms.)

### Building the prefix sum array

```c
int N;
cin >> N;
int A[N];
for (i = 0; i < N; i++)
{
    cin >> A[i];
}

int P[N];
sum = 0;
for (i = 0; i < N; i++)
{
    sum += A[i];
    P[i] = sum;
}   // Building the Prefix Sum array
```

### Answering queries using prefix sum

```c
int Q;
cin >> Q;
for (i = 0; i < Q; i++)
{
    int L, R;
    cin >> L >> R;

    if (L == 0)
    {
        print(P[R]);
    }
    else
    {
        print(P[R] - P[L-1]);
    }

    if (L == 0)
    {
        print(P[R]);
    }
    else
    {
        print(P[R] - P[L-1]);
    }
}
```

Time Complexity: `O(N + Q)` ✓ (much better than `O(N*Q)` which TLEs)

Space Complexity: `O(N)` (for the prefix sum array)

### Summary

For any query `(L, R)` asking for `A[L] + A[L+1] + ... + A[R]`, using a **Prefix Sum Array**:
```
Sum(L, R) = P[R]              if L == 0
          = P[R] - P[L-1]     if L != 0
```

### Indexing note

- **0-based indexing**: L starts from 0
  ```
  A = [12, 7, 8, 5, 9]
       0   1  2  3  4
  ```
  Query for indices `1..2` → `L=0` case uses `P[R]`; `L≠0` uses `P[R]-P[L-1]`.

- **1-based indexing**: L starts from 1
  ```
  A = [12, 7, 8, 5, 9]
       1   2  3  4  5
  ```
  Equivalent query would be `3..5`.

---

## Prefix Sum — More Query Variants

### Example: Count of vowels in a substring range

```
S = "abcdaefghijkl"
     0123456789...
```

Given queries `(L, R)`: count number of vowels (`a`, `e`, `i`, `o`, `u`) in `S[L..R]`.

Example queries:
- `(0, 4) → 2`
- `(3, 7) → 2`
- `(5, 12) → 2`
- `(0, 12) → 4`

Naive approach:
```
For every query [L, R]:  (Q queries)
    count = 0
    for (i : L → R):      (N)
        if S[i] is a vowel:
            count++
    print(count)
```
Time Complexity: `O(Q*N)`.

This can be optimized using a **prefix count array** (same prefix-sum idea, but tracking cumulative vowel counts instead of cumulative sums) to answer each query in O(1), giving overall `O(N + Q)`.

### Example: Count of even numbers in a range

```
A = [17, 16, 9, 8, 3, 8, 11, 7, 5]
     0   1   2 3 4 5 6   7 8
```
(even numbers marked: 16, 8, 8 → contribute to an "is-even" prefix array)

Query examples:
- `(1, 6) → 9 + 3 + 11 = ` even-index sum illustration: `12 + 11 = 23`
- `(5, 8) → 11 + 5 = 16`

The same prefix-sum technique applies: build a prefix array of a binary indicator (e.g., 1 if element satisfies a condition like "is even", 0 otherwise), then answer range queries in O(1).

---

## Subarrays

A **subarray** is a continuous part of an array.

- Defined by `L` (start) and `R` (end), with `L ≤ R`.

Example:
```
A = [1, 7, 8, 5, 11]
     0  1  2  3   4
```

For a fixed `L`, `R` ranges over `L, L+1, ..., N-1`. E.g.:
- `L=0`: `R = 0, 1, 2, 3, 4`
- `L=1`: `R = 1, 2, 3, 4`
- `L=2`: `R = 2, 3, 4`
- `L=3`: `R = 3, 4`
- `L=4`: `R = 4`

### Counting number of subarrays

For array `[A₀, A₁, A₂, ..., A_{N-1}]`:

| L | R range | # subarrays |
|---|---|---|
| 0 | 0,1,2,...,N-1 | N |
| 1 | 1,2,...,N-1 | N-1 |
| 2 | 2,3,...,N-1 | N-2 |
| ... | ... | ... |
| N-1 | N-1 | 1 |

Total number of subarrays = `N + (N-1) + (N-2) + ... + 1 = N(N+1)/2`

### Printing all subarrays

```c
A = [1, 7, 5, 9];

for (L = 0; L < N; L++)
{
    for (R = L; R < N; R++)
    {
        // [L, R]
        for (i = L; i <= R; i++)
        {
            print(A[i]);
        }
        cout << endl;
    }
}
```

Time Complexity: `O(N³)`
Space Complexity: `O(1)`

Example output (sums shown alongside for illustration):
```
1                 → 1
1 7               → 8
1 7 5             → 13
1 7 5 9           → 22
7                 → 7
7 5               → 12
7 5 9             → 21
5                 → 5
5 9               → 14
9                 → (9)
```

---

## Sum of All Subarrays (Google)

Naive triple-loop approach:

```c
sum = 0;
for (L = 0; L < N; L++)
{
    for (R = L; R < N; R++)
    {
        sum = 0;
        for (i = L; i <= R; i++)
        {
            sum += A[i];
        }
        ans += sum;
    }
}
print(ans);
```
Where `sum = A[L] + A[L+1] + ... + A[R]`.

Time Complexity: `O(N³)`
Space Complexity: `O(1)`

### Optimized using Prefix Sum

```c
ans = 0;
for (L = 0; L < N; L++)
{
    for (R = L; R < N; R++)
    {
        if (L == 0)
        {
            sum = P[R];
        }
        else
        {
            sum = P[R] - P[L-1];
        }
        ans += sum;
    }
}
print(ans);
```

Time Complexity: `O(N²)`
Space Complexity: `O(N)`

Constraint example: `1 ≤ N ≤ 10⁵`.

There exists a further optimization achieving `O(N)` time, `O(1)` space (see Contribution Technique below).

---

## Contribution Technique

Idea: instead of computing the sum of every subarray directly, compute how many times each element `A[i]` contributes across **all** subarrays, then multiply that count by `A[i]`.

### Example walkthrough

```
A = [1, 7, 5, 9]
```

Enumerate subarrays containing prefixes of each starting element and observe contribution:
```
1                     → 1
1, 7                  → 8
1, 7, 5               → 13
1, 7, 5, 9            → 22

7                     → 7
7, 5                  → 12
7, 5, 9               → 21

5                     → 5
5, 9                  → 14

9                     → (9)
```

Element contribution formula:
```
(1 × 4) + (7 × 6) + (5 × 6) + (9 × 4)
= 4 + 42 + 30 + 36
= 46 + 66
= 112
```

General formula:
```
A = [A0, A1, A2, A3, A4, ..., A_{N-1}]

ans = (A0 × #subarrays where A0 appears)
    + (A1 × #subarrays where A1 appears)
    + (A2 × #subarrays where A2 appears)
    + ...
```

For the example `A = [1, 7, 5, 9]`, the counts are:
```
A0 = 4
A1 = 6
A2 = 6
A3 = 4
```

### Deriving "# of subarrays containing A[i]"

To count subarrays containing index `i`:
- Choose a **start** anywhere from `0` to `i` → `i+1` options
- Choose an **end** anywhere from `i` to `N-1` → `N-i` options

```
A = [A0, A1, A2, A3, ..., Ai, Ai+1, ..., A_{N-1}]

start options = i + 1
end options   = (N-1) - (i) + 1 = N - i

# subarrays containing A[i] = start options × end options

[ 1, 3 , 5 , 4, 5 , 6, 8, 9]
4 how many times , then start options 1 to 4 (4), end options 4 to 9 (5) => 4 * 5 = 20
```

### Final O(N) algorithm

```c
ans = 0;
for (i = 0; i < N; i++)
{
    ans += (i+1) * (N-i) * A[i];
}
print(ans);
```

Time Complexity: `O(N)`
Space Complexity: `O(1)`

This is the optimal solution for "Sum of All Subarrays" — improving from `O(N³)` (naive) → `O(N²)` (prefix sum) → `O(N)` (contribution technique).

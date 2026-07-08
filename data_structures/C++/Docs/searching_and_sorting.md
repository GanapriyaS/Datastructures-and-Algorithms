# Searching & Sorting 

Combined notes from the **sort** whiteboard (searching + sorting algorithms) and the **offline video notes** (insertion sort + merging sorted arrays).

## Table of Contents
- **Searching**
  1. [What is Searching?](#1-what-is-searching)
  2. [Linear Search](#2-linear-search)
  3. [Binary Search](#3-binary-search)
- **Sorting**
  4. [What is Sorting?](#4-what-is-sorting)
  5. [Selection Sort](#5-selection-sort)
  6. [Bubble Sort](#6-bubble-sort)
  7. [Insertion Sort](#7-insertion-sort)
  8. [Merge Two Sorted Arrays](#8-merge-two-sorted-arrays)

---

## 1. What is Searching?

**Searching** = to look for something / to find something in the data.

- If the data is **sorted**, we can use **Binary Search** (much faster).
- If the data is **unsorted**, we fall back to **Linear Search**.

---

## 2. Linear Search

Check every element one by one. Use a `flag` to remember whether the target was found.

```cpp
bool flag = false;

for (int i = 0; i < N; i++)
{
    if (A[i] == target)
    {
        flag = true;
        break;
    }
}

if (flag)
{
    cout << "YES";
}
else
{
    cout << "NO";
}
```

**Optimization when the data is sorted (ascending):** we can *break early*. Once an element is bigger than the target, the target can't appear later.

```cpp
bool flag = false;

for (int i = 0; i < N; i++)
{
    if (A[i] == target)
    {
        flag = true;
        break;
    }

    if (A[i] > target)   // sorted → no point looking further
    {
        break;
    }
}
```

---

## 3. Binary Search

**Requires sorted data.** Repeatedly look at the middle element and throw away half the search space.

```cpp
bool flag = false;

int l = 0;
int r = N - 1;

while (l <= r)
{
    int mid = (l + r) / 2;

    if (A[mid] == target)
    {
        flag = true;
        break;
    }
    else if (A[mid] > target)
    {
        // target is smaller → search in the left half
        r = mid - 1;
    }
    else
    {
        // target is bigger → search in the right half
        l = mid + 1;
    }
}

if (flag)
{
    cout << "YES";
}
else
{
    cout << "NO";
}
```

**Dry run** — find `target = 60` in a 17-element sorted array (indices `0…16`):

```
A = [2, 3, 4, 6, 7, 9, 10, 11, 15, 17, 28, 35, 40, 60, 65, 69, 70]
     0  1  2  3  4  5   6   7   8   9  10  11  12  13  14  15  16
```

| Step | l | r | mid = (l+r)/2 | A[mid] | Action |
|------|---|---|----------------|--------|--------|
| 1 | 0 | 16 | 8  | 15 | 15 < 60 → `l = mid + 1` = 9 |
| 2 | 9 | 16 | 12 | 40 | 40 < 60 → `l = mid + 1` = 13 |
| 3 | 13 | 16 | 14 | 65 | 65 > 60 → `r = mid - 1` = 13 |
| 4 | 13 | 13 | 13 | 60 | **found** ✅ |

> **Descending order?** The direction flips: if `A[mid] > target` search the **right**, else search the **left** (e.g. `A = [100, 50, 30, 10]`).

```
A = [2, 3, 11, 14, 15]
     0  1   2   3   4
Target = 10

0 4 (mid = 2)
0 1 (mid = 1)
2 1 ( l > r ) // not found

```
---

## 4. What is Sorting?

**Sorting** = to rearrange data in a specific order — **Ascending** or **Descending**.

Common sorting algorithms:

1. Selection Sort
2. Bubble Sort
3. Insertion Sort
4. Merge Sort
5. Heap Sort
6. Quick Sort

The first three are covered below.

---

## 5. Selection Sort

**Idea**
1. Select the **minimum** in the unsorted region `[i, N-1]`.
2. Bring it to the front by **swapping** it with the first element of the unsorted region.

Each pass grows the sorted prefix by one:

```
A = [11, 2, 14, 18, 20, 27, 3, 40]   i = 0 → min is 2  → swap to front
A = [2, 11, 14, 18, 20, 27, 3, 40]   i = 1 → min is 3
A = [2, 3, 14, 18, 20, 27, 11, 40]   i = 2 → min is 11
A = [2, 3, 11, 18, 20, 27, 14, 40]   ...
                        ⋮
A = [2, 3, 11, 14, 18, 20, 27, 40]   sorted

i = 0 -----------> 1 to N - 1 (unsorted)
i = 1 -----------> 2 to N - 1 (unsorted)
i = 2 -----------> 3 to N - 1 (unsorted)
```

**Code**

```cpp
for (int i = 0; i < N; i++)
{
    // find min in the unsorted region [i, N-1]
    int mn = A[i];
    int loc = i;

    for (int j = i + 1; j < N; j++)
    {
        if (A[j] < mn)
        {
            mn = A[j];
            loc = j;
        }
    }

    swap(A[i], A[loc]);
}
```

---

## 6. Bubble Sort

**Idea:** if two adjacent elements are in the **wrong order**, swap them. After every pass, the **largest element of the unsorted region bubbles to the end**.

```
A = [10, 4, 12, 6, 22]

       ⋮   (repeated adjacent swaps)

    A = [4, 10, 12, 6, 22]   
            ^
    A = [4, 10, 12, 6, 22]      
                 ^
    A = [4, 10, 6, 12, 22]  
                    ^     
    A = [4, 10, 6, 12, 22]  
                        ^
--------------------------------
    A = [4, 10, 6, 12, 22]   
            ^
    A = [4, 6, 10, 12, 22]      
                 ^
    A = [4, 6, 10, 12, 22] 
                    ^
--------------------------------
    A = [4, 6, 10, 12, 22]   
            ^
    A = [4, 6, 10, 12, 22]      
                 ^
--------------------------------
    A = [4, 6, 10, 12, 22]   
            ^

A = [4, 6, 10, 12, 22]   sorted

======================================================


unsorted                sorted

[0, N-1]                   -
[0, N-2]                [N-1, N-1]
[0, N-3]                [N-2, N-1]
.
.
.
[0, 1]                  [2, N-1] 
[0, 0]                  [1, N-1]

```

The unsorted region is `[0, i]`; the sorted region grows from the right.

**Code**

```cpp
for (int i = N - 1; i >= 1; i--)
{
    // [0, i] is unsorted, do the swaps there
    for (int j = 0; j < i; j++)
    {
        if (A[j] > A[j + 1])
        {
            swap(A[j], A[j + 1]);
        }
    }
}
```

**Optimization — break early if already sorted.** If a full pass makes **no swaps**, the array is already sorted, so stop.

```cpp
for (int i = N - 1; i >= 1; i--)
{
    bool swapped = false;

    for (int j = 0; j < i; j++)
    {
        if (A[j] > A[j + 1])
        {
            swapped = true;
            swap(A[j], A[j + 1]);
        }
    }

    if (swapped == false)   // no swaps → array was already sorted
    {
        break;
    }
}
```

---

## 7. Insertion Sort

**Idea:** treat `A[0..i-1]` as the sorted part. Take `A[i]` as `temp`, **shift** every larger element one step to the right, then drop `temp` into the gap — like inserting a card into a sorted hand.

**Trace** for `A = [23, 1, 10, 5, 2, 4]` (green = sorted region, `temp` holds the element being inserted):

```
23 is sorted part and 1 to 4 is unsorted, try to insert one element from unsorted to sorted region
A = [23, 1, 10, 5, 2, 4]      temp = 1   → [1, 23, 10, 5, 2, 4] (23 sorted)
      j   i
A = [1, 23, 10, 5, 2, 4]      temp = 10  → [1, 10, 23, 5, 2, 4] (1, 23 sorted)
         j    i
A = [1, 10, 23, 5, 2, 4]      temp = 5   → [1, 5, 10, 23, 2, 4] (1, 10, 23 sorted)
             j   i
A = [1, 5, 10, 23, 2, 4]      temp = 2   → [1, 2, 5, 10, 23, 4] (1, 5, 10, 23 sorted)
                j   i
A = [1, 2, 5, 10, 23, 4]      temp = 4   → [1, 2, 4, 5, 10, 23] (1, 2, 5, 10, 23 sorted)
                   j   i
```

**Code**

```cpp
for (int i = 1; i < N; i++)
{
    int temp = A[i];
    int j = i - 1;

    while (j >= 0 && A[j] > temp)
    {
        A[j + 1] = A[j];   // shift the larger element right
        j--;
    }

    A[j + 1] = temp;       // insert temp into the gap
}
```

---

## 8. Merge Two Sorted Arrays

**Problem:** given two already-sorted arrays `A` (size `N`) and `B` (size `M`), produce a single sorted array `C` (size `N + M`).

```
A = [1, 7, 8, 150, 160]                 (N = 5)
B = [2, 5, 6, 9, 18, 19, 59]            (M = 7)
C = [1, 2, 5, 6, 7, 8, 9, 18, 19, 59, 150, 160]   (N + M = 12)
```

**Idea (two pointers):** walk `i` over `A` and `j` over `B`; at each step copy the **smaller** front element into `C[k]` and advance that pointer. When one array runs out, copy whatever is left of the other.

```cpp
int C[N + M];
int i = 0, j = 0, k = 0;

// merge while both arrays still have elements
while (i < N && j < M)
{
    if (A[i] < B[j])
    {
        C[k] = A[i];
        i++;
    }
    else
    {
        C[k] = B[j];
        j++;
    }
    k++;
}

// copy the leftovers of A (if any)
while (i < N)
{
    C[k] = A[i];
    i++;
    k++;
}

// copy the leftovers of B (if any)
while (j < M)
{
    C[k] = B[j];
    j++;
    k++;
}
```

**Small dry run** — `A = [10, 20]`, `B = [7, 8, 15]`:

```
compare 10 & 7  → take 7     C = [7]
compare 10 & 8  → take 8     C = [7, 8]
compare 10 & 15 → take 10    C = [7, 8, 10]
compare 20 & 15 → take 15    C = [7, 8, 10, 15]
B done → copy leftover 20     C = [7, 8, 10, 15, 20]
```

> This merge step is the core building block of **Merge Sort**.

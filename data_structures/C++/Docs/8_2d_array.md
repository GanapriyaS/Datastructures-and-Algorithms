# 2D Arrays in C++

## Table of Contents
1. [What is a 2D Array?](#1-what-is-a-2d-array)
2. [Declaring & Taking Input](#2-declaring--taking-input)
3. [Creating & Accessing Elements](#3-creating--accessing-elements)
4. [Print Row-wise](#4-print-row-wise)
5. [Print Column-wise](#5-print-column-wise)
6. [Wave Print (Row-wise)](#6-wave-print-row-wise)
7. [Wave Print (Column-wise)](#7-wave-print-column-wise)
8. [Boundary Print](#8-boundary-print)
9. [Row with Maximum 1s](#9-row-with-maximum-1s)

> **Where are 2D arrays used?** Board games — Snake, Tetris, 2048, Connect-4, Tic-Tac-Toe, Chess — are all naturally represented as grids.

---

## 1. What is a 2D Array?

- A **2D array is a collection of 1D arrays** (a grid / table).
- It has **Rows (N)** and **Columns (M)** → an `N × M` array.
- Every cell is addressed by **two indices**: `arr[row][col]`.

For a `5 × 4` grid (5 rows, 4 columns):

```
        col:  0    1    2    3
      row 0 [    |    |    |    ]   ← Top-Left = (0,0),  Top-Right = (0,3)
      row 1 [    |    |    |    ]
      row 2 [    |    |    |    ]
      row 3 [    |    | 12 |    ]   ← arr[3][2] = 12
      row 4 [    |    |    |    ]   ← Bottom-Left = (4,0), Bottom-Right = (4,3)
```

| Position | Index |
|----------|-------|
| Top-Left | `(0, 0)` |
| Top-Right | `(0, 3)` |
| Bottom-Left | `(4, 0)` |
| Bottom-Right | `(4, 3)` |

```cpp
arr[3][2] = 12;   // row 3, column 2
```

---

## 2. Declaring & Taking Input

**Recall — 1D array** needs one loop:

```cpp
int arr[N];
for (int i = 0; i < N; i++)
{
    cin >> arr[i];
}
```

**2D array** needs a **nested loop** (outer = rows, inner = columns):

```cpp
int arr[N][M];
for (int i = 0; i < N; i++)
{
    for (int j = 0; j < M; j++)
    {
        cin >> arr[i][j];
    }
}
```

Layout of the elements:

```
A(0,0)  A(0,1)  A(0,2) ... A(0,M-1)
A(1,0)  A(1,1)  A(1,2) ... A(1,M-1)
  :
A(N-1,0) A(N-1,1) ...      A(N-1,M-1)
```

---

## 3. Creating & Accessing Elements

```cpp
int arr[5][4];   // arr[#rows][#cols]  → 5 rows, 4 columns
```

Just like a 1D array, all cells start with **garbage values** (shown as `?`) until assigned.

```cpp
arr[2][2] = 10;                 // assign
arr[3][1] = 15;                 // assign

cout << arr[3][1] << endl;      // read / print
cin  >> arr[3][1];              // overwrite from input
```

```
        col:  0    1    2    3
      row 0 [ ?  | ?  | ?  | ?  ]
      row 1 [ ?  | ?  | ?  | ?  ]
      row 2 [ ?  | ?  | 10 | ?  ]   ← arr[2][2] = 10
      row 3 [ ?  | 15 | ?  | ?  ]   ← arr[3][1] = 15
      row 4 [ ?  | ?  | ?  | ?  ]
```

---

## 4. Print Row-wise

Go row by row; inside each row go left to right. Print a newline after each row.

```cpp
for (int i = 0; i < N; i++)
{
    for (int j = 0; j < M; j++)
    {
        cout << arr[i][j] << " ";
    }
    cout << endl;
}
```

---

## 5. Print Column-wise

Fix a column, then walk down all rows. So the **column loop is outer** and the **row loop is inner**.

```cpp
for (int j = 0; j < M; j++)
{
    // col no. is fixed
    for (int i = 0; i < N; i++)
    {
        cout << arr[i][j] << " ";
    }
}
```

**Example**

```
        col:  0   1   2   3
      row 0 [ 1 | 7 | 6 | 2 ]
      row 1 [ 5 | 9 | 8 | 3 ]
      row 2 [ 1 | 6 | 8 | 5 ]
      row 3 [ 2 | 1 | 6 | 6 ]
      row 4 [ 5 | 9 |12 | 7 ]
```

Output (column by column):

```
Col 0: 1 5 1 2 5   Col 1: 7 9 6 1 9   Col 2: 6 8 8 6 12   Col 3: 2 3 5 6 7
```

---

## 6. Wave Print (Row-wise)

- **Even rows** → print **Left → Right**
- **Odd rows** → print **Right → Left**

```cpp
for (int i = 0; i < N; i++)
{
    if (i % 2 == 0)
    {
        // Left → Right
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
    else
    {
        // Right → Left
        for (int j = M - 1; j >= 0; j--)
        {
            cout << arr[i][j] << " ";
        }
    }
}
```

For the grid above, the wave output is:

```
1 7 6 2  3 8 9 5  1 6 8 5  6 6 1 2  5 9 12 7
```

---

## 7. Wave Print (Column-wise)

- **Even columns** → print **Top → Bottom**
- **Odd columns** → print **Bottom → Top**

```cpp
for (int j = 0; j < M; j++)
{
    if (j % 2 == 0)
    {
        // top → bottom
        for (int i = 0; i < N; i++)
        {
            cout << arr[i][j] << " ";
        }
    }
    else
    {
        // bottom → top
        for (int i = N - 1; i >= 0; i--)
        {
            cout << arr[i][j] << " ";
        }
    }
}
```

---

## 8. Boundary Print

Print only the outer border: **first row → last column → last row → first column** (like walking around the edge). Print each cell once, so the later loops skip corners already printed.

```cpp
// First Row (row = 0): left → right
for (int j = 0; j < M; j++)
{
    cout << arr[0][j] << " ";
}

// Last Col (col = M-1): top → bottom, skip the corner already printed
for (int i = 1; i < N; i++)
{
    cout << arr[i][M - 1] << " ";
}

// Last Row (row = N-1): right → left, skip the last-col corner
for (int j = M - 2; j >= 0; j--)
{
    cout << arr[N - 1][j] << " ";
}

// First Col (col = 0): bottom → top, skip both corners
for (int i = N - 2; i >= 1; i--)
{
    cout << arr[i][0] << " ";
}
```

```
        col:  0 ........... M-1
      row 0 [ ━━━━━━━━━━━━━━━━ ]   ← first row (whole)
            [ ┃            ┃  ]   ← first col & last col
       :    [ ┃            ┃  ]
     row N-1[ ━━━━━━━━━━━━━━━━ ]   ← last row
```

---

## 9. Row with Maximum 1s

> Given a matrix of 0s and 1s, find the **row that contains the most 1s** (print its index).

**Idea:** count the 1s in each row; keep track of the best row seen so far (`bestRow`) and the highest count (`mxCount`).

```cpp
int bestRow = -1;
int mxCount = 0;

for (int i = 0; i < N; i++)
{
    int count = 0;
    for (int j = 0; j < M; j++)
    {
        if (arr[i][j] == 1)
        {
            count++;
        }
    }

    if (count > mxCount)
    {
        mxCount = count;
        bestRow = i;
    }
}

cout << bestRow << endl;
```

**Example**

```
      row 0 [ 0  1  1 ]  → 2 ones
      row 1 [ 1  0  0 ]  → 1 one
      row 2 [ 1  0  1 ]  → 2 ones
      row 3 [ 1  1  1 ]  → 3 ones  ✅ best
      row 4 [ 0  0  1 ]  → 1 one
      row 5 [ 1  0  1 ]  → 2 ones
```

Answer: `bestRow = 3` (with `mxCount = 3`).

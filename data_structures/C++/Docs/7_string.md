# Strings in C++

## Table of Contents
1. [Check Same (two characters)](#1-check-same-two-characters)
2. [ASCII Values](#2-ascii-values)
3. [Character to ASCII](#3-character-to-ascii)
4. [ASCII to Character](#4-ascii-to-character)
5. [Convert to Lowercase](#5-convert-to-lowercase)
6. [Check Character (lower / upper / digit / special)](#6-check-character-lower--upper--digit--special)
7. [What is a String?](#7-what-is-a-string)

---

## 1. Check Same (two characters)

> Given two characters in the input, check whether they are the same or not.

```
Input:  a b        Input:  a a
Output: NO         Output: YES
```

**Solution**

```cpp
char ch1, ch2;
cin >> ch1 >> ch2;

if (ch1 == ch2)
{
    cout << "YES";
}
else
{
    cout << "NO";
}
```

---

## 2. ASCII Values

Every basic character on the keyboard is assigned a **unique numeric value** by the computer, called its **ASCII value**.

**Key ranges to remember**

| Characters | ASCII (decimal) |
|------------|-----------------|
| `A` – `Z` (uppercase) | 65 – 90 |
| `a` – `z` (lowercase) | 97 – 122 |
| `0` – `9` (digits) | 48 – 57 |
| `[SPACE]` | 32 |

**The +32 / −32 relationship**

```
        + 32
   ┌───────────┐
Upper         lower
   └───────────┘
        − 32
```

- **lowercase = uppercase + 32** (e.g. `'A'` = 65 → `'a'` = 97)
- **uppercase = lowercase − 32**

This gap of 32 between the same letter's cases is the trick behind case-conversion.

---

## 3. Character to ASCII

> Given a character, print its ASCII value.

```
Input:  A        Input:  a
Output: 65       Output: 97
```

**Solution** — cast the `char` to `int`.

```cpp
char ch;
cin >> ch;

cout << (int)ch;
```

---

## 4. ASCII to Character

> Given an ASCII value, print the corresponding character.

```
Input:  65       Input:  97
Output: A        Output: a
```

**Solution** — cast the `int` to `char`.

```cpp
int val;
cin >> val;

cout << (char)val;
```

---

## 5. Convert to Lowercase

> Given an alphabet (lowercase/uppercase), convert it into lowercase.

```
Input:  A        Input:  a
Output: a        Output: a
```

**Idea:** only uppercase letters need changing. If the character is between `'A'` and `'Z'`, add 32 to shift it into lowercase.

**Solution**

```cpp
char ch;
cin >> ch;

if (ch >= 'A' && ch <= 'Z')
{
    ch += 32;
}

cout << ch;
```

---

## 6. Check Character (lower / upper / digit / special)

> Check whether a given character is lowercase, uppercase, digit or a special character.

```
Input:  a       B        7        @
Output: lower   upper    digit    special
```

**Solution** — test each range in turn; anything that matches none is *special*.

```cpp
char ch;
cin >> ch;

if (ch >= 'a' && ch <= 'z')
{
    cout << "lower";
}
else if (ch >= 'A' && ch <= 'Z')
{
    cout << "upper";
}
else if (ch >= '0' && ch <= '9')
{
    cout << "digit";
}
else
{
    cout << "special";
}
```

---

## 7. What is a String?

A **collection / sequence of characters** stored at continuous memory locations.

For example, `"Dhruv"` is stored as individual characters:

```
 ┌─────┬─────┬─────┬─────┬─────┐
 │ 'd' │ 'h' │ 'r' │ 'u' │ 'v' │
 └─────┴─────┴─────┴─────┴─────┘
```

In C++, there are **2 ways** to impleemulateai-dev
dtx_copen_ecosystem￼
￼
Type / to search
￼
￼
￼￼
Repository navigation
Code
Issues
82
 (82)
Pull requests
9
 (9)
Actions
Projects
Security and quality
Insights
Settings
Actions: emulateai-dev/dtx_copen_ecosystem
Actions
New workflow
All workflows
Alembic migrations
￼
Container Image Releaser
￼
Container Image Releaser - Preflight Worker
￼
Scheduler container image
￼
Management
Caches
Attestations
Runners
Usage metrics
Performance metrics
GitHub Actions workflows can't be executed on this repository.
Your account's billing is currently locked. Please update your payment information.

Container Image Releaser
￼
￼
ci-docker-push.yml
402 workflow runs
￼
Event
￼
Status
￼
Branch
￼
Actor
This workflow has a workflow_dispatch event trigger.
Run workflow 
Container Image Releaser
Container Image Releaser #435: Manually run by ganapriyas-dtx
sprint-11	
Today at 8:28 PM
 1sment a string:

| 1) Char Array (C style) | 2) String (STL) |
|--------------------------|-----------------|
| `char s[100];` | `string s;` |
| Ends with `'\0'` (null terminator) | Easier to use |
| ❌ Manual memory handling | ✅ Automatic memory management |
| ❌ More error-prone | ✅ Less error-prone |
| | ✅ More inbuilt functions available |

```cpp
// 1) Char Array (C style)
char s[100];

// 2) String (STL)  ← preferred
string s;
```


## Table of Contents
- **Basics**
  1. [Reading a String & Accessing Characters](#1-reading-a-string--accessing-characters)
  2. [Printing the Whole String](#2-printing-the-whole-string)
  3. [`cin >>` Stops at Whitespace](#3-cin--stops-at-whitespace)
  4. [`getline` — Reading a Full Line](#4-getline--reading-a-full-line)
  5. [Reading Multiple Words](#5-reading-multiple-words)
- **Problems**
  6. [E — Brothers](#6-e--brothers)
  7. [Lexicographical Order (which word comes first)](#7-lexicographical-order-which-word-comes-first)
  8. [G — Replace Character](#8-g--replace-character)
  9. [N — Count Words](#9-n--count-words)

---

## 1. Reading a String & Accessing Characters

A `string` can be read with `cin`, its length obtained with `.size()`, and each character accessed by index like an array (`s[i]`).

```cpp
#include <iostream>
using namespace std;

int main()
{
    string s;        // ""
    cin >> s;

    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        cout << s[i] << ' ';
    }
}
```

```
Input:  dhruv
Output: d h r u v
```

---

## 2. Printing the Whole String

You don't need a loop just to print — a `string` can be sent to `cout` directly.

```cpp
int main()
{
    string s;        // ""
    cin >> s;        // "dhruv"
    cout << s;
}
```

```
Input:  dhruv
Output: dhruv
```

---

## 3. `cin >>` Stops at Whitespace

`cin >> s` reads only **up to the first space** — it grabs a single word, not the whole line.

```cpp
int main()
{
    string s;        // ""
    cin >> s;        // "hello" / "hello world"
    cout << s;
}
```

```
Input:  hello world
Output: hello          ← "world" is ignored
```

---

## 4. `getline` — Reading a Full Line

To read an entire line **including spaces**, use `getline(cin, s)`.

```cpp
int main()
{
    string s;        // ""
    getline(cin, s);
    cout << s;
}
```

```
Input:  hello world hello hello
Output: hello world hello hello
```

---

## 5. Reading Multiple Words

Because each `cin >>` reads one whitespace-separated word, several `cin >>` statements pick up consecutive words in order.

```cpp
int main()
{
    string s;        // ""
    cin >> s;        // "hello" / "hello world"

    string s2;
    cin >> s2;

    string s3;
    cin >> s3;

    string s4;
    cin >> s4;

    cout << s << s2 << s3 << s4;
}
```

```
Input:  hello world hello hello
Output: helloworldhellohello
```

---

## 6. E — Brothers

> Two people are considered **brothers** if and only if their **last names are the same**.
>
> **Input:** two lines. Each line contains two strings: `FirstName` and `LastName`. All strings contain only English letters, length 1 to 100.
> **Output:** print `YES` if they are brothers, otherwise `NO`.

```
input           input
Ali Hassan      Alice Singh
Omar Hassan     Bob Kumar
output          output
YES             NO
```

**Solution** — read both first/last name pairs; compare only the last names.

```cpp
#include <iostream>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;      // person 1: FirstName LastName

    string t1, t2;
    cin >> t1 >> t2;      // person 2: FirstName LastName

    if (s2 == t2)         // compare last names
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
```

---

## 7. Lexicographical Order (which word comes first)

> You are given two words `A` and `B`. A word `A` comes before `B` in **lexicographical (dictionary) order** if:
> - at the first position where they differ, `A` has a smaller character than `B`, or
> - `A` is a prefix of `B` and `A ≠ B`.
>
> Determine which word appears first in the dictionary.
>
> **Input:** first line = word `A`, second line = word `B`. Both are lowercase English letters, length 1 to 1000.
> **Output:** print `A` if `A` comes before `B`, `B` if `B` comes before `A`, `Equal` if `A = B`.

```
input           input
apple           same
apricot         same
output          output
A               Equal
```

Strings support the relational operators (`<`, `==`, `>`) directly, and they compare **lexicographically**.

**Solution**

```cpp
#include <iostream>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    if (a < b)
    {
        cout << "A";
    }
    else if (a == b)
    {
        cout << "SAME";
    }
    else
    {
        cout << "B";
    }
}
```

> The class also showed a shorter two-branch version (`if (s < t) cout << "A"; else cout << t;`) while building up to the full three-way comparison above.

---

## 8. G — Replace Character

> You are given a string `s` of lowercase English letters and two characters `c1` and `c2`. Replace **every occurrence** of `c1` in `s` with `c2` and print the resulting string.
>
> **Input:** first line = non-empty string `s` (`1 ≤ |s| ≤ 10⁶`); second line = two lowercase letters `c1` and `c2` separated by a space.
> **Output:** the required string.

```
input           input
abacaba         aaaa
a b             a c
output          output
bbbcbbb         cccc
```

**Solution** — walk the string; wherever the character equals `c1`, overwrite it with `c2`.

```cpp
#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    char ch1, ch2;
    cin >> ch1 >> ch2;

    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ch1)
        {
            s[i] = ch2;
        }
    }

    cout << s << endl;
}
```

---

## 9. N — Count Words

> You are given a string `S` of English letters and spaces. A **word** is a maximal contiguous sequence of letters. Words are separated by exactly one space, and the first character of `S` is not a space.
>
> **Input:** one line — the string `S` (`1 ≤ |S| ≤ 10⁵`, letters and spaces only).
> **Output:** one integer — the number of words in `S`.

```
input
hello world this is CP
output
5
```

**Idea:** with single-space separators, the number of words is `(number of spaces) + 1`. Use `getline` so the spaces are actually read.

**Solution**

```cpp
#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int n = s.size();

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            cnt++;
        }
    }

    cout << cnt + 1 << endl;   // words = spaces + 1
}
```

---

## Quick Recap

| Concept | Key point |
|---------|-----------|
| `cin >> s` | reads **one word**, stops at whitespace |
| `getline(cin, s)` | reads the **whole line**, including spaces |
| `s.size()` | length of the string |
| `s[i]` | access / modify the character at index `i` |
| `cout << s` | prints the full string (no loop needed) |
| `a < b`, `a == b` | strings compare **lexicographically** (dictionary order) |
| Count words | `spaces + 1` when separated by single spaces |

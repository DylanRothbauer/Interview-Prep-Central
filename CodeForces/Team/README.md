# 🏆 Problem 231A - Team

## 📂 Problem Details

| **Problem ID** | **Name**  | **Topics**         | **Difficulty** | **Participants Solved** |
|----------------|-----------|--------------------|----------------|--------------------------|
| 231A           | Team      | brute force, greedy| 800            | 340,082                  |

---

## 📄 Problem Description

Three friends—Petya, Vasya, and Tonya—decide to participate in a programming contest. They will only solve a problem if at least **two of them are sure** about the solution.

Given the confidence levels of the three friends for each problem, determine how many problems they will solve during the contest.

---

### 🔢 Input
- The first line contains an integer `n` (1 ≤ `n` ≤ 1000), the number of problems.
- The next `n` lines each contain three integers (`0` or `1`):
  - The first integer represents Petya's confidence.
  - The second integer represents Vasya's confidence.
  - The third integer represents Tonya's confidence.

---

### 🔡 Output
- A single integer, the total number of problems the friends will solve.

---

## 🔑 Examples

| **Input**                       | **Output** | **Explanation**                                                                                                                                          |
|---------------------------------|------------|----------------------------------------------------------------------------------------------------------------------------------------------------------|
| 3                               | 2          | For the first problem: Petya and Vasya are sure (2 are confident).<br>Second problem: all three are sure (3 are confident).<br>Third problem: only Petya is confident. |
| 2                               | 1          | For the first problem: only Petya is confident (1 is confident).<br>Second problem: Vasya and Tonya are sure (2 are confident).                          |

---

## 🧠 Key Insights

- **Confidence Rule:** A problem is solved if **at least two friends** are confident about it.
- **Counting Confident Friends:** For each problem, sum the three integers. If the sum is ≥ 2, the problem will be solved.

---

## 🏆 Solution

### Approach:
1. Parse the input to get the number of problems (`n`) and the confidence levels for each problem.
2. Initialize a counter (`count`) to zero.
3. For each problem:
   - Compute the sum of confidence levels.
   - If the sum is ≥ 2, increment the counter.
4. Output the counter as the total number of problems solved.

---

### Complexity:
- **Time Complexity:** O(n), where `n` is the number of problems.
  - Each problem is processed in constant time.
- **Space Complexity:** O(1), as no additional data structures are needed.

---

### Example Code (C++)
```cpp
#include <iostream>
using namespace std;

int main() {
    int n, count = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int petya, vasya, tonya;
        cin >> petya >> vasya >> tonya;
        if (petya + vasya + tonya >= 2) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}


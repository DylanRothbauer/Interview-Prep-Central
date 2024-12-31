# ✂️ Problem 71A - Way Too Long Words

## 📂 Problem Details

| **Problem ID** | **Name**               | **Topics** | **Difficulty** | **Participants Solved** |
|----------------|------------------------|------------|----------------|--------------------------|
| 71A           | Way Too Long Words    | strings    | 800            | 400,219                  |

---

## 📄 Problem Description

Some words, such as "localization" or "internationalization," are so long that writing them repeatedly can be tiresome. A word is considered **too long** if its length is strictly greater than 10 characters. Such words should be abbreviated.

### Abbreviation Rules:
1. Retain the **first letter** and **last letter** of the word.
2. Replace the letters in between with their count.

#### Examples:
- `"localization"` → `"l10n"`
- `"internationalization"` → `"i18n"`

---

### 🔢 Input
- An integer `n` (1 ≤ n ≤ 100), the number of words.
- The following `n` lines each contain a single word consisting of lowercase Latin letters (length: 1 to 100).

---

### 🔡 Output
- For each word:
  - Print the abbreviation if the word is too long.
  - Print the word unchanged if it is not too long.

---

## 🔑 Examples

| **Input**                                                                 | **Output**                                   |
|---------------------------------------------------------------------------|---------------------------------------------|
| 4                                                                         |                                             |
| word                                                                      | word                                        |
| localization                                                              | l10n                                        |
| internationalization                                                      | i18n                                        |
| pneumonoultramicroscopicsilicovolcanoconiosis                             | p43s                                       |

---

## 🧠 Key Insights

- **Too Long Definition:** Words longer than 10 characters should be abbreviated.
- **Transformation Rules:** Keep the first and last letter; count the letters in between.

---

## 🏆 Solution

### Approach:
1. Parse the input for the number of words (`n`) and the list of words.
2. For each word:
   - If its length is ≤ 10, keep it unchanged.
   - Otherwise, form an abbreviation using:
     - The first letter.
     - The count of middle letters.
     - The last letter.
3. Output the results.

### Complexity:
- **Time Complexity:** O(n), where `n` is the number of words. Each word is processed once.
- **Space Complexity:** O(1), as only a constant amount of space is used for processing.

---


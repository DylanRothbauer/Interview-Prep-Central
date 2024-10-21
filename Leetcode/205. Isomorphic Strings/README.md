# 205. Isomorphic Strings

**Solved**  
**Difficulty:** Easy  

## Problem Description  
Given two strings `s` and `t`, determine if they are **isomorphic**.

Two strings are **isomorphic** if the characters in `s` can be replaced to get `t`.

- All occurrences of a character must be replaced with **another character** while preserving the **order** of characters.
- No two characters may map to the same character, but a character may map to itself.

---

## Example 1
**Input:**  
s = "egg" t = "add"  
**Output:**  
true  

**Explanation:**  
- The strings `s` and `t` can be made identical by:  
  - Mapping `'e'` to `'a'`.  
  - Mapping `'g'` to `'d'`.  

---

## Example 2
**Input:**  
s = "foo" t = "bar  
**Output:**  
false  

**Explanation:**  
- The strings cannot be made identical as `'o'` needs to map to both `'a'` and `'r'`.

---

## Example 3
**Input:**  
s = "paper" t = "title"  
**Output:**  
true  

---

## Constraints  
- `1 <= s.length <= 5 * 10^4`  
- `t.length == s.length`  
- `s` and `t` consist of any valid ASCII characters.

---


# 🍕 One Pizza - Hash Code 2022 Practice Problem

## Problem Summary
You're opening a small pizzeria, but with a twist: you offer only one type of pizza, and you need to decide which ingredients to include. Each potential customer has specific ingredients they like and ingredients they dislike. Your goal is to select a combination of ingredients for the pizza that maximizes customer satisfaction. A customer will buy the pizza if it contains **all** the ingredients they like and **none** of the ingredients they dislike.

## Input Format
- **First Line:** Number of potential clients, `C`.
- **Next 2 * C Lines:** For each client:
  - A line with the number of liked ingredients followed by the names of those ingredients.
  - A line with the number of disliked ingredients followed by the names of those ingredients.

## Output Format
- A single line with:
  - An integer `N`, the number of ingredients on the pizza.
  - A space-separated list of `N` ingredients.

## Scoring
Your score is the number of clients who will buy your pizza based on the selected ingredients.

## Constraints
- \(1 \leq C \leq 10^5\)
- Ingredient names consist of 1 to 15 lowercase ASCII characters or digits.

## Example
**Input:**  
3  
2 cheese peppers  
0  
1 basil  
1 pineapple  
2 mushrooms tomatoes  
1 basil  

**Output:**  
4 cheese mushrooms tomatoes peppers

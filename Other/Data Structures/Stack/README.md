# Stack Data Structure

## Introduction

A stack is a data structure that follows the **Last In, First Out (LIFO)** principle. This means that the last element added to the stack will be the first one to be removed. 

### Visualizing a Stack:

Consider a stack of books:
- **Push operation**: Adding a book to the stack is similar to placing it on top of the pile.
- **Pop operation**: Removing a book is done by taking the top one off, not from the middle or bottom.
- **Peek operation**: You can check the top book without removing it.
- **Check if empty**: If there are no books left, the stack is empty.
- **Size**: The number of books represents the stack's size.

In programming, stacks are widely used for tasks like undo mechanisms, function call stacks, and parsing.

## Push and Pop Operations

### Push Operation:
- Adds an element to the top of the stack.
- **Steps**:
  1. Check if the stack is full (stack overflow).
  2. If not, place the element at the top and update the "top" pointer.

### Pop Operation:
- Removes the top element from the stack.
- **Steps**:
  1. Check if the stack is empty (stack underflow).
  2. Remove the top element and update the "top" pointer.

### Example (Java):
```java
static final int MAX_SIZE = 101;
static int[] a = new int[MAX_SIZE];
static int top = -1;

static void push(int ele) {
    if (top < MAX_SIZE - 1) {
        top++;
        a[top] = ele;
        System.out.println("Pushed: " + ele);
    } else {
        System.out.println("Stack is full. Cannot push: " + ele);
    }
}

static int pop() {
    if (top >= 0) {
        int ele = a[top];
        top--;
        System.out.println("Popped: " + ele);
        return ele;
    } else {
        System.out.println("Stack is empty. Cannot pop.");
        return -1;
    }
}

static int peek() {
    if (top >= 0) {
        int ele = a[top];
        System.out.println("Peeked: " + ele);
        return ele;
    } else {
        System.out.println("Stack is empty. Cannot peek.");
        return -1;
    }
}

static boolean is_empty() {
    return top == -1;
}

static boolean is_full() {
    return top >= MAX_SIZE;
}

```
## Exercise: Implement a Stack to Reverse a String
You will implement a basic stack to reverse a string using the stack's LIFO property.  

**Task:**  
Update the push() and pop() functions to output the reversed string.

### Sample:
Input: Hello, World!  
Output: !dlroW ,olleH

```java
import java.util.Scanner;

class Stack {
    private static final int STACK_CAPACITY = 101;
    private char[] stackArray = new char[STACK_CAPACITY];
    private int topIndex = -1;

    void push(char character) {
        if (isFull()) {
            System.out.println("Stack is full");
        } else {
            topIndex++;
            stackArray[topIndex] = character;
        }
    }

    char pop() {
        if (isEmpty()) {
            return '-';
        } else {
            char character = stackArray[topIndex];
            topIndex--;
            return character;
        }
    }

    boolean isEmpty() {
        return topIndex == -1;
    }

    boolean isFull() {
        return topIndex >= STACK_CAPACITY - 1;
    }
}

class ReverseString {
    public static void main(String[] args) {
        String inputString = "Hello, World!";
        int inputLength = inputString.length();

        Stack charStack = new Stack();

        for (int i = 0; i < inputLength; i++) {
            char currentChar = inputString.charAt(i);
            charStack.push(currentChar);
        }

        StringBuilder reversedString = new StringBuilder();
        while (!charStack.isEmpty()) {
            reversedString.append(charStack.pop());
        }

        System.out.println(reversedString.toString());
    }
}

```
## Use Cases of Stack
Stacks are used in scenarios that follow the **LIFO** principle:
- **Expression Evaluation:** Converting infix to postfix expressions for evaluation.
- **Function Calls and Recursion:** Managing function calls in programming languages.
- **Undo/Redo Functionality:** Used in applications for undo/redo features.
- **Backtracking Algorithms:** Applied in algorithms like depth-first search.
- **Parsing and Syntax Analysis:** Checking for balanced parentheses and symbols.

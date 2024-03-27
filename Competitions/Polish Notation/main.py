# Overview

class Node:
    def __init__(self, inputs):
        self.val = inputs.pop(0)
        self.left, self.right = -1, -1
        if self.val == "+" or self.val == "*":
            self.left = Node(inputs)
            self.right = Node(inputs)

    def to_string(self):
        res = ""
        if self.left != -1:
            res += str("("+ self.left.to_string())
        res += self.val
        if self.right != -1:
            res += str(self.right.to_string()+")")
        return res

    # Added function to evaluate the arthritic expression
    def eval(self):
        if self.val.isdigit():
            return int(self.val)
        left_val = self.left.eval()
        right_val = self.right.eval()
        if self.val == "+":
            return left_val + right_val
        elif self.val == "*":
            return left_val * right_val

inputs = input("").split()
root = Node(inputs)

print(root.to_string())
print(root.eval())

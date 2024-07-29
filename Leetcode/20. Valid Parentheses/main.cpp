class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
            }
            else {
                // Check if the stack is empty or the top does not match the expected opening parenthesis
                if (stack.empty() ||
                    (s[i] == ')' && stack.top() != '(') ||
                    (s[i] == '}' && stack.top() != '{') ||
                    (s[i] == ']' && stack.top() != '[')) {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.empty();
    }
};
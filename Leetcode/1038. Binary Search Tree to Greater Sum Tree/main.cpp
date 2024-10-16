/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 /*
 O(n) time complexity, where n is the number of nodes, and O(h) space complexity due to the recursion stack, where h is the height of the tree.
 */
class Solution {
public:
    // Keep track of cumulative sum.
    int sum = 0;

    TreeNode* bstToGst(TreeNode* root) { // Reverse in-order traversal
        if (root == nullptr) {
            return nullptr;  // Base case for recursion
        }

        // Traverse the right subtree first (greater nodes)
        bstToGst(root->right);

        // Update the cumulative sum and modify the node's value
        sum += root->val;
        root->val = sum;

        // Traverse the left subtree (smaller nodes)
        bstToGst(root->left);

        return root;  // Return the modified tree
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void reverse(TreeNode* leftChild, TreeNode* rightChild, int level) {
        if (!leftChild || !rightChild)
            return;
        if (level % 2 == 0) {
            swap(leftChild->val, rightChild->val);
        }
        reverse(leftChild->left, rightChild->right, level + 1);
        reverse(leftChild->right, rightChild->left, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root)
            return NULL;
        int level = 0;
        reverse(root->left, root->right, 0);
        return root;
    }
};
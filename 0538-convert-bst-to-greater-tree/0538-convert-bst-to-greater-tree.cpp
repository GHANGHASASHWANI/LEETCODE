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
    void inOrderTraversal(TreeNode* root, int& sum) {
        if (!root)
            return;
        inOrderTraversal(root->left, sum);
        sum += root->val;
        inOrderTraversal(root->right, sum);
    }

    void updateValues(TreeNode* root, int& sum) {
        if (!root)
            return;
        updateValues(root->left, sum);
        int temp = root->val;
        root->val = sum;
        sum = sum - temp;
        updateValues(root->right, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        inOrderTraversal(root, sum);
        updateValues(root, sum);
        return root;
    }
};
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
class Solution {
private:
    int maximumSum(TreeNode* root, int &sum) {
        if (!root) return 0;

        int leftSum = max(0, maximumSum(root->left, sum));
        int rightSum = max(0, maximumSum(root->right, sum));

        sum = max(sum, root->val + leftSum + rightSum);

        return root->val + max(leftSum, rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        int maximum = maximumSum(root, sum);

        return sum;
    }
};
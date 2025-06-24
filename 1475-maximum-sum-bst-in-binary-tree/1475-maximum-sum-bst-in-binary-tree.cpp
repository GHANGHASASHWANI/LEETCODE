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
class currNode {
    public:
    int mini, maxi, sum;
    bool isValid;
};
class Solution {
private:
    currNode findSum(TreeNode* root, int &summ) {
        if (!root) {
            return {INT_MAX, INT_MIN, 0, true};
        }

        currNode left = findSum(root->left, summ);
        currNode right = findSum(root->right, summ);

        if (root->val > left.maxi && root->val < right.mini && left.isValid && right.isValid) {
            summ = max(summ, root->val + left.sum + right.sum);
        } else {
            left.isValid = false;
        }

        currNode newNode;
        
        newNode.maxi = max({root->val, right.maxi});
        
        newNode.mini = min({left.mini, root->val});
        
        newNode.sum =  root->val + left.sum + right.sum;

        newNode.isValid = left.isValid & right.isValid;

        return newNode;
        
    }
public:
    int maxSumBST(TreeNode* root) {
        int sum = 0;
        currNode obj = findSum(root, sum);

        return sum;
    }
};
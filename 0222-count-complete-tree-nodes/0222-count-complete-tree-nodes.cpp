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
    int totalHeight(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = Height1(root);
        int rightHeight = Height2(root);

        if (leftHeight == rightHeight) {
            return  (1 << leftHeight) - 1;
        }
        
        return 1 + totalHeight(root->left) + totalHeight(root->right);
    }

    int Height1(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->left;
        }
        return height;
    }
    int Height2(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->right;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        return totalHeight(root);
    }
};
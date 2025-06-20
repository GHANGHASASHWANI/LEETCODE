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
    int traverseDFS(TreeNode* root, int &required) {
        if (!root) {
            return 1;
        }

        int left = traverseDFS(root->left, required);
        int right = traverseDFS(root->right, required);

        if (left ==  0 || right == 0) {
            required++;
            return 2;
        } else if (left == 2 || right == 2) {
            return 1;
        } 
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        int requiredCameras = 0;
        int total = traverseDFS(root, requiredCameras);
        if (total == 0) requiredCameras++;
        return requiredCameras;
    }
};
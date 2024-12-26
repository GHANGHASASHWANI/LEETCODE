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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> answer;
        queue<TreeNode*> levelOrder;
        levelOrder.push(root);

        while (not levelOrder.empty()) {
            int size = levelOrder.size();
            int maxi = INT_MIN;
            for (int index = 0; index < size; index++) {
                TreeNode* node = levelOrder.front();
                levelOrder.pop();
                maxi = max(maxi, node->val);
                if (node->left)
                    levelOrder.push(node->left);
                if (node->right)
                    levelOrder.push(node->right);
            }
            answer.push_back(maxi);
        }
        return answer;
    }
};
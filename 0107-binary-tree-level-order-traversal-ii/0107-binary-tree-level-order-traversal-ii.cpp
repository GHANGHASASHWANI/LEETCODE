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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> traverse;

        traverse.push(root);

        while (!traverse.empty()) {
            vector<int> currLevel;

            int size = traverse.size();

            for (int i = 0; i < size; i++) {
                TreeNode* currNode = traverse.front();
                traverse.pop();

                currLevel.push_back(currNode->val);

                if (currNode->left) traverse.push(currNode->left);
                if (currNode->right) traverse.push(currNode->right);
            }
            ans.push_back(currLevel);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
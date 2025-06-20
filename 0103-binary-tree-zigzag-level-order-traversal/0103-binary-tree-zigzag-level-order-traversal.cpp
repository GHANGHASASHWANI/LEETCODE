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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> zigzag;
        queue<TreeNode*> traverse;
        traverse.push(root);
        int level = 0;

        while (not traverse.empty()) {
            vector<int> currLevel;
            int size = traverse.size();
            // cout<<size<<"ok"<<endl;
            for (int i = 0; i < size; i++) {
                TreeNode* top = traverse.front();
                traverse.pop();
                currLevel.push_back(top->val);
                // cout<<top->val<<endl;
                if (top->left != NULL) {
                    traverse.push(top->left);
                }
                if (top->right != NULL) {
                    traverse.push(top->right);
                }
            }
            if (level % 2 != 0) reverse(currLevel.begin(), currLevel.end());
            zigzag.push_back(currLevel);
            level++;
        }
        return zigzag;
    }
};
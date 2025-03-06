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
    vector< int > v;

    void solve(TreeNode* root, int maxi, int mini){
        if(! root) return;
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        v.push_back(abs(maxi - mini));
        solve(root->left, maxi, mini);
        solve(root->right, maxi, mini);
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root, root->val, root->val);
        int ans = *max_element(v.begin(), v.end());
        return ans;
    }
};
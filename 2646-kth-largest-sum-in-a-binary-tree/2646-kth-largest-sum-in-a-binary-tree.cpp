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

    void levelOrder(TreeNode* root, vector<long long> &totalSum){
        queue< pair<TreeNode*, int>> qu;
        qu.push({root, 0});
        while(qu.size()){
            TreeNode* temp = qu.front().first;
            int level = qu.front().second;
            qu.pop();
            totalSum[level] += temp->val;

            if(temp->right) qu.push({temp->right, level + 1});
            if(temp->left) qu.push({temp->left, level+1});
        }
    }
    int level(TreeNode* root){
        if(!root) return 0;
        return 1 + max(level(root->right), level(root->left));
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root) return 0;
        vector< long long > totalSum(100005);
        levelOrder(root, totalSum);
        int levels = level(root);
        if(levels < k) return -1;
        sort(totalSum.begin(), totalSum.end());
        int size = totalSum.size();

        return  totalSum[size - k];

    }
};
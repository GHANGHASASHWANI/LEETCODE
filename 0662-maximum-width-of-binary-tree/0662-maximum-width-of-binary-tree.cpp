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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> traverse;
        traverse.push({root, 0});
        unsigned long long maxi = 0;

        while (! traverse.empty()) {
            int size = traverse.size();
            unsigned long long start = traverse.front().second;
            unsigned long long first = -1, last = -1;

            for (int i = 0; i < size; i++) {
                pair<TreeNode*, unsigned long long> curr = traverse.front();
                traverse.pop();
                TreeNode* currNode = curr.first;
                unsigned long long level = curr.second;

                level -= start;

                if (i == 0) first = level;
                if (i == size - 1) last = level;

                if (currNode->left) traverse.push({currNode->left, 2*level});
                if (currNode->right) traverse.push({currNode->right, 2*level + 1});

                maxi = max(maxi, last - first + 1);
             }
        }
        return maxi;
    }
};
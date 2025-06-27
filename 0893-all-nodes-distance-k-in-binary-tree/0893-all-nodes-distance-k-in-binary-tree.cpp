/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void findParent(TreeNode* root, vector<TreeNode*> &parent) {
        if (!root) return;

        if (root->left) {
            parent[root->left->val] = root;
        }
        if (root->right) {
            parent[root->right->val] = root;
        }

        findParent(root->left, parent);
        findParent(root->right, parent);
    }

    vector<int> findTarget(TreeNode* root, vector<TreeNode*> parent, TreeNode* target, int k) {
        queue<pair<int, TreeNode*>> traverse;
        vector<int> result;
        set<TreeNode*> visited;

        traverse.push({0, target});
        visited.insert(target);

        while (not traverse.empty()) {
            pair<int, TreeNode*> curr = traverse.front();

            int level = curr.first;
            TreeNode* currNode = curr.second;

            if (level == k) {
                result.push_back(currNode->val);
            }

            visited.insert(currNode);

            traverse.pop();

            if (currNode->left && not visited.count(currNode->left)) {
                traverse.push({level + 1, currNode->left});
            }
            if (currNode->right && not visited.count(currNode->right)) {
                traverse.push({level + 1, currNode->right});
            }
            if (parent[currNode->val]  && not visited.count(parent[currNode->val])) {
                traverse.push({level + 1, parent[currNode->val]});
            }
        }
        return result;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> parent(501, NULL);
        findParent(root, parent);
        vector<int> result = findTarget(root, parent, target, k);
        return result;
    }
};
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
    TreeNode* first;
    void findNode(TreeNode* root, int start){
        if(root == NULL) return;
        if(root->val == start) {
            first = root;
            return;
        }

        findNode(root->left, start);
        findNode(root->right, start);
      
    }

    void parentChild(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &childParent){
        if(root == NULL) return;

        if(root->left){
            childParent[root->left] = root;
        }
        if(root->right){
            childParent[root->right] = root;
        }
        parentChild(root->left, childParent);
        parentChild(root->right, childParent);
    }
    int amountOfTime(TreeNode* root, int start) {
        findNode(root, start);

        unordered_map<TreeNode*, TreeNode*> childParent;
        parentChild(root, childParent);

        set<TreeNode*> isInfected;

        queue<pair< TreeNode*, int>> BFS;
        BFS.push({first, 0});
        isInfected.insert(first);

        int maxLevel = 0;

        while(BFS.size() > 0){
            TreeNode* currNode = BFS.front().first;
            int level = BFS.front().second;
            maxLevel = max(maxLevel, level);
            BFS.pop();
            if(currNode->left){
                if(isInfected.find(currNode->left) == isInfected.end()){
                    BFS.push({currNode->left, level+1});
                    isInfected.insert(currNode->left);
                }
            }
            if(currNode->right){
                if(isInfected.find(currNode->right) == isInfected.end()){
                    BFS.push({currNode->right, level+1});
                    isInfected.insert(currNode->right);
                }
            }
            if(childParent.find(currNode) != childParent.end()){
                if(isInfected.find(childParent[currNode]) == isInfected.end()){
                    BFS.push({childParent[currNode], level +1});
                    isInfected.insert(childParent[currNode]);
                }
            }
        }
        return maxLevel;
    }
};
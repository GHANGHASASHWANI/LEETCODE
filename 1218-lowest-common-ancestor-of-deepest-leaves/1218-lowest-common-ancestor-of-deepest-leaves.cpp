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
    void lvOrder(TreeNode* root, vector<TreeNode*> &arr){
        queue<TreeNode*> qu;
        qu.push(root);
        arr.push_back(root);

        while(!qu.empty()){
            int size = qu.size();
            arr.clear();

            for(int i = 0; i < size; i++){
                TreeNode* node = qu.front();
                qu.pop();
                arr.push_back(node);
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
            }
        }
    }

    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root == p || root == q){
            return root;
        }
        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);

        if(!left) return right;

        else if(!right) return left;

        else return root;

    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> arr;
        lvOrder(root, arr);

        if(arr.size() == 1){
            return LCA(root, arr[0], NULL);
        }
        else{
            return LCA(root, arr[0], arr.back());
        }
        return root;
    }
};
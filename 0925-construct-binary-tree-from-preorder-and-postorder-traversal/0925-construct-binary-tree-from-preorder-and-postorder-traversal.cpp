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
TreeNode* build(vector<int>& pre, int prelo, int prehi, vector<int>& post, int postlo,int posthi){
    if(postlo>posthi || prelo>prehi) return NULL;
    TreeNode* root=new TreeNode(post[posthi]);
    if(postlo==posthi) return root;

    int i=postlo;
    while(i<=posthi){
        if(post[i]==pre[prelo+1]) break;
        i++;
    }
    int leftcount=i-postlo;
    root->left=build(pre,prelo+1,prelo+leftcount+1,post,postlo,i);
    root->right=build(pre,prelo+leftcount+2,prehi,post,i+1,posthi-1);

    return root;
}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        return build(preorder,0,n-1,postorder,0,n-1);
    }
};
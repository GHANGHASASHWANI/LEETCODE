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

    int totalSwap(vector<int> & arr){
        // for(auto i : arr){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        vector<int> target(arr.begin(), arr.end());
        sort(target.begin(), target.end());
        int ans = 0;
        unordered_map<int, int> pos;

        for(int i =0; i < arr.size(); i++){
            pos[arr[i]] = i;
        }

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] != target[i]){
                ans++;

                int curr = pos[target[i]];
                pos[arr[i]] = curr;
                swap(arr[i], arr[curr]); 
            }
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        queue< TreeNode* > qu;

        qu.push(root);
        int ans = 0;
        while(!qu.empty()){
           int level = qu.size();
           vector<int> element;
           for(int i =0; i < level; i++){
            TreeNode* top = qu.front();
            element.push_back(top->val);
            qu.pop();
            if(top->left){
                qu.push(top->left);
            }
            if(top->right){
                qu.push(top->right);
            }
           }
           ans+= totalSwap(element);
        }       
        return ans; 
    }
};
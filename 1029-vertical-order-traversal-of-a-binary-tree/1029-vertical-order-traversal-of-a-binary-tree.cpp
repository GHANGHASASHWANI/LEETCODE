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
    // vector<pair< int , int>> temp;
    // void inOrder(TreeNode* root, int level){
    //     if(!root) return;
    //     temp.push_back({level, root->val});
    //     inOrder(root->left, level - 1);
    //     inOrder(root->right, level + 1);
    // }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // temp.clear();
        // inOrder(root, 0);
        // sort(temp.begin(), temp.end());
        // map< int, vector< int >> values;

        // for(auto val : temp){
        //     values[val.first].push_back(val.second);
        // }
        // vector< vector< int >> answer;

        // for(auto i : values){
        //     answer.push_back(i.second);
        // }
        // return answer;

        /****************** BFS *****************/

        map< int, vector< int >> levelValues;

        queue< pair< int, TreeNode*>> qu;
        qu.push({0, root});
        while(!qu.empty()){
            int total = qu.size();
            map< int, vector< int >> tempValues;

            for(int i = 0; i < total; i++){
                int level = qu.front().first;
                TreeNode* node = qu.front().second;
                qu.pop();
                tempValues[level].push_back(node->val);
                sort(tempValues[level].begin(), tempValues[level].end());
                if(node->left != NULL) qu.push({level - 1, node->left});
                if(node->right != NULL) qu.push({level + 1, node->right});
            }

            for(auto i : tempValues){
                for(auto j : i.second){
                    levelValues[i.first].push_back(j);
                }
            }
            
        }
        vector<vector< int >> answer;

        for(auto i : levelValues){
            answer.push_back(i.second);
        }
        return answer;
    }
};
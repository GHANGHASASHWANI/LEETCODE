class Codec {
public:

   string serialize(TreeNode* root) {
        if (!root) return "";

        string result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            if (node) {
                result += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "-1001 ";
            }
        }

    return result;
}


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;

        vector<string> temp;

        stringstream ss(data);

        string x;

        while (ss>>x) {
            temp.push_back(x);
        }

        queue<TreeNode*> qu;
        TreeNode* curr = new TreeNode();
        curr->val = stoi(temp[0]);
        qu.push(curr);

        TreeNode* root = curr;
        int i = 1;
        while (not qu.empty() && i < temp.size()) {
           TreeNode* currNode = qu.front();
           qu.pop();

           if (i < temp.size() && temp[i] != "-1001") {
                currNode->left = new TreeNode(stoi(temp[i]));
                qu.push(currNode->left);
           }
           i++;

           if (i < temp.size() && temp[i] != "-1001") {
                currNode->right = new TreeNode(stoi(temp[i]));
                qu.push(currNode->right);
           }
           i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
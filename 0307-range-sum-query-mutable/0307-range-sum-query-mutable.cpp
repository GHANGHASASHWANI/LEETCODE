class NumArray {
private:
    void build(vector<int> &tree, vector<int> &arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;

        build(tree, arr, node * 2, start, mid);
        build(tree, arr, node * 2 + 1, mid + 1, end);

        tree[node] = tree[node*2] + tree[node*2 + 1];

    }
    int query(vector<int> &tree, vector<int> &arr, int node, int start, int end, int l, int r) {
        if (end < l || start > r) return 0;
        if (start == end) {
            return tree[node];
        } else if (start >= l && end <= r) {
            return tree[node];
        } 
        int mid = (start + end) / 2;
        int left = query(tree, arr, 2*node, start, mid, l, r);
        int right = query (tree, arr, 2*node + 1, mid + 1,end,  l, r);

        return left + right;
    }

    void update(vector<int> &tree, vector<int> &arr, int node, int start, int end, int pos, int val) {
        if (start == end) {
            arr[pos] = val;
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (pos >= start && pos <= mid) {
            update(tree, arr, node*2, start, mid, pos, val);
        } else {
            update(tree, arr, node*2 + 1, mid + 1, end, pos, val);
        }
        tree[node] = tree[node*2] + tree[node* 2 + 1];
    }
public:
    vector<int> tree;
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr = nums;
        tree.resize(arr.size() * 4, 0);
        build(tree, arr, 1, 0, arr.size() - 1);
    }
    
    void update(int index, int val) {
        update(tree, arr, 1, 0, arr.size() - 1, index, val);
    }   
    
    int sumRange(int left, int right) {
        return query(tree, arr, 1, 0, arr.size() - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
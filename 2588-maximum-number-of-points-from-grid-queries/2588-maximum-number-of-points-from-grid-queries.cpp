class Solution {
public:
    int rows[4] = {0, 0, -1, 1};
    int cols[4] = {1, -1, 0, 0};
    typedef tuple< int, int, int> tpp;
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector< int > sortedQuery(queries.begin(), queries.end());
        sort(sortedQuery.begin(), sortedQuery.end());
        map<int, int> mpp;
        int n = grid.size(), m = grid[0].size();
        vector<vector< bool >> visited(n, vector<bool> (m, false));
        visited[0][0] = true;
        priority_queue<tpp, vector<tpp>, greater<tpp>> pq;

        pq.push({grid[0][0], 0, 0});
        int i = 0;
        int ans  = 0;
        int size = sortedQuery.size();
        while(i < size){
            while(!pq.empty() && get<0>(pq.top()) < sortedQuery[i]){
                auto [val, idx1, idx2] = pq.top();
                pq.pop();
                ans++;
                int row = idx1;
                int col = idx2;
                for(int k =0; k < 4; k++){
                    int newRow = row + rows[k];
                    int newCol = col + cols[k];
                    // cout<<newRow<<" "<<newCol<<endl;
                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol] ){
                        visited[newRow][newCol] = true;
                        cout<<newRow<<" "<<newCol<<endl;

                        pq.push({grid[newRow][newCol], newRow, newCol}); 
                    }
                }
            }
                mpp[sortedQuery[i]] = ans;
                i++;
                // pq.push({val, idx1, idx2});
            
        }
        vector< int > answer;
        for(int i =0; i < queries.size(); i++){
            answer.push_back(mpp[queries[i]]);
        }
        return answer;
    }
};
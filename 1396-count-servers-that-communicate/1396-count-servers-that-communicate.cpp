class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        map< int, vector< pair< int, int > >> rows;
        map<int, vector< pair< int, int>>> cols;

        for(int i =1; i <= grid.size(); i++){
            for(int j =1; j <= grid[0].size(); j++){
                if(grid[i-1][j-1] == 1){
                    rows[i].push_back({i,j});
                    cols[j].push_back({i,j});
                }
            }
        }
        set< pair< int, int > > ans;
        for(auto i : rows){
            if(i.second.size() > 1){
                for(auto j : i.second){
                    ans.insert({j.first, j.second});
                }
            }
        }
         for(auto i : cols){
            if(i.second.size() > 1){
                for(auto j : i.second){
                    ans.insert({j.first, j.second});
                }
            }
        }
        for(auto i : ans){
            cout<<i.first<<" " << i.second<<endl;
        }
        return ans.size();
    }
};
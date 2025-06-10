class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<pair<int, int>>> prefix(n+1, vector<pair<int, int>> (m + 1, {0, 0}));
        int ans = 0;

        for (int i =  1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int prevX1 = prefix[i-1][j].first;
                int prevX2 = prefix[i][j - 1].first;

               int prevY1 = prefix[i-1][j].second;
               int prevY2 = prefix[i][j - 1].second;

               int diaX = prefix[i-1][j-1].first;
               int diaY = prefix[i-1][j - 1].second;


               if (grid[i -  1][j - 1] == 'X') {
                    prefix[i][j].first = prevX1 + prevX2 - diaX + 1;
                    prefix[i][j].second = prevY1 + prevY2 - diaY;
               } else if (grid[i-1][j-1] == 'Y') {
                   prefix[i][j].first = prevX1 + prevX2 - diaX ;
                    prefix[i][j].second = prevY1 + prevY2 - diaY + 1;
               } else {
                    prefix[i][j].first = prevX1 + prevX2 - diaX ;
                    prefix[i][j].second = prevY1 + prevY2 - diaY;
              
               }

               if (prefix[i][j].first == prefix[i][j].second && prefix[i][j].first > 0) {
                ans++;
               }
            //    cout<<prefix[i][j].first<<" "<<prefix[i][j].second<<", ";
            }
            // cout<<endl;
        }
        return ans;
    }
};
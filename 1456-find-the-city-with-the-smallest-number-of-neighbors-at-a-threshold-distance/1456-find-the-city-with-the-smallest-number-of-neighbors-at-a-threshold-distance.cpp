class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int> (n, INT_MAX));
        for(int i = 0; i < n; i++){
            distance[i][i] = 0;
        }
        for(auto edge : edges){
            int vertex1 = edge[0], vertex2 = edge[1], weight = edge[2];
            distance[vertex1][vertex2] = weight;
            distance[vertex2][vertex1] = weight;
        }

        for(int via = 0; via < n; via++){
            for(int i =0; i < n; i++){
                for(int j =0; j < n; j++){
                    if(distance[i][via] != INT_MAX && distance[via][j]  != INT_MAX){
                        distance[i][j] = min(distance[i][j], distance[i][via] + distance[via][j]);
                    }
                }
            }
        }

        int cnt = n;
        int cityNo = -1;

        for(int i =0; i < n; i++){
            int total = 0;
            for(int j =0; j < n; j++){
                if(distance[i][j] <= distanceThreshold){
                    total++;
                }
            }   
            if(total <= cnt){
                cnt = total;
                cityNo = i;
            }
        }
        return cityNo;
    }
};
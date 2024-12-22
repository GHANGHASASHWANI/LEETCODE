class Solution {
    #define p pair<int,int>
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        int qz= q.size(),n=h.size();
        vector<int> ans(qz,-1);
        vector<vector<p>> v(n);
        for(int i=0;i<qz;i++){
            if(q[i][0]>q[i][1]) swap(q[i][0],q[i][1]);
            if(h[q[i][0]]< h[q[i][1]] || q[i][0]==q[i][1]) ans[i]=q[i][1];
            else{
                v[q[i][1]].push_back({h[q[i][0]],i});
            }
        }
        int j=0;
        priority_queue<p,vector<p>,greater<p>> pq;
        for(int i=0;i<n;i++){
           while(j<=i){
            for(auto k:v[j]) pq.push(k);
            j++;
           }
           while(!pq.empty() && pq.top().first< h[i]){ans[pq.top().second]=i; pq.pop();}
        }
        return ans;
    }
};
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<times.size();i++){
            pq.push({times[i][0],{times[i][1],i}});
        }
        int n=times.size();
        vector<int>occupied(n+1,-1);
        while(!pq.empty()){
            int start=pq.top().first;
            int end=pq.top().second.first;
            int frnd=pq.top().second.second;
            pq.pop();
            int occupy_seat=-1;
            for(int i=0;i<occupied.size();i++){
                if(occupied[i]==-1||occupied[i]<=start){
                    occupied[i]=end;
                    occupy_seat=i;
                    break;
                }
            }
            if(frnd==targetFriend){
                return occupy_seat;
            }
        }
        return -1;
        
    }
};
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long total = 0;
        for(auto i : gifts){
            pq.push(i);
        }
        while(k--){
            int top = pq.top();
            pq.pop();
            pq.push(sqrtl(top));
        }
        while(!pq.empty()){
            total += pq.top();
            pq.pop();
        }
        return total;
    }
};
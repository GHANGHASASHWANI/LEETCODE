class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue< long long, vector<long long> , greater<long long>> pq;
        for(auto i : nums){
            pq.push(i);
        }
        int ans = 0;
        while(pq.size() > 1){
            long long top1 = pq.top();
            pq.pop();
            long long top2 = pq.top();
            pq.pop();
            if(top1 >= k){
                break;
            }else{
                ans++;
            }
            long long need = min(top1, top2)*2 + max(top1, top2);
            pq.push(need);
        }
        return ans;
    }
};
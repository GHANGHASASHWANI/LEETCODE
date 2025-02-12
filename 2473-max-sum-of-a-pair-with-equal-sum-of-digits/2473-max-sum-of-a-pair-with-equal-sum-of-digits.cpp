class Solution {
public:
    int findSum(int x){
        int sum = 0;
        while(x > 0){
            sum += x % 10;
            x/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        priority_queue< pair<int, int> > pq;

        for(auto i : nums){
            int ans = findSum(i);
            pq.push({ans, i});
        }
        int ans = -1;
        while(pq.size() > 1){
            int sum1 = pq.top().first;
            int digit1 = pq.top().second;
            pq.pop();

            int sum2 = pq.top().first;
            int digit2 = pq.top().second;
            pq.pop();

            if(sum1 == sum2){
                ans = max(ans, digit1 + digit2);
                pq.push({sum1, max(digit1, digit2)});
            }
            else{
                pq.push({sum2, digit2});
            }
        }
        return ans;
    }
};
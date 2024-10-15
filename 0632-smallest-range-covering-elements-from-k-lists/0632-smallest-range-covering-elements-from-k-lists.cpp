class Solution {
public:
typedef pair<int, pair<int, int>> pp;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue< pp, vector<pp>, greater<pp>> pq;

        int maxi = nums[0][0];
        for(int index = 0; index < nums.size(); index++){
            maxi = max(nums[index][0], maxi);
            pq.push({nums[index][0], {index, 0}});
        }

        int start = (pq.top()).first;
        int end = maxi;

        while(true){
            int currMin = (pq.top()).first;
            int currRow = ((pq.top()).second).first;
            int currCol = ((pq.top()).second).second;
            pq.pop();

            if(maxi - currMin < end - start){
                end = maxi;
                start = currMin;
            }
            
            currCol++;
            
            if(nums[currRow].size() == currCol) break;
            pq.push({nums[currRow][currCol], {currRow, currCol}});
            maxi = max(maxi, nums[currRow][currCol]);
        }
        return {start,end};

    }
};
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maximumScore =  0;
        unordered_set<int> preVisited;
        int slow = 0, fast = 0, currScore = 0;

        // Traversing the array values
        while (fast < nums.size()) {
            int currValue = nums[fast];
            // If the currElement is not present
            if (not preVisited.count(currValue)) {
                currScore += currValue;
                preVisited.insert(currValue);
                fast++;
            } else { 
                // Increase the slow pointer until unique value arrives
                while (preVisited.count(nums[fast])) {
                    currScore -= nums[slow];
                    preVisited.erase(nums[slow]);
                    slow++;
                }
            }
            // Calculate the maximum each time
            maximumScore = max(maximumScore, currScore);
        }
        
        return maximumScore;
    }
};
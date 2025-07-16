class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int maxLen = INT_MIN;

        int evenNum = 0, oddNum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) evenNum++;
            if (nums[i] % 2 != 0) oddNum++;
        }

        bool evenFlag = true;
        int count1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (evenFlag && nums[i] % 2 == 0) {
                evenFlag = false;
                count1++;
            } else if (not evenFlag && nums[i] % 2 != 0) {
                evenFlag = true;
                count1++;
            }
        }

        bool oddFlag = true;
        int count2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (oddFlag && nums[i] % 2 != 0) {
                count2++;
                oddFlag = false;
            } else if (not oddFlag && nums[i] % 2  == 0) {
                count2++;
                oddFlag = true;
            }
        }
        maxLen = max({count1, count2, evenNum, oddNum});

        return maxLen;
    }
};
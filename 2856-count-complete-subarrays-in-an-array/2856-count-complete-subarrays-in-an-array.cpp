class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        map<int, int> distinct;

        for (auto& element : nums){
            distinct[element]++;
        }

        int fast = 0, slow = 0, answer = 0;
        map<int, int> temp;

        while(fast < nums.size()){
            temp[nums[fast]]++;
            while (temp.size() == distinct.size()){
                answer += (nums.size() - fast);
                if(slow <= fast){
                    temp[nums[slow]]--;
                    if(temp[nums[slow]] == 0){
                        temp.erase(nums[slow]);
                    }
                    slow++;
                }
            }
            fast++;
        }   
        return answer;
    }
};
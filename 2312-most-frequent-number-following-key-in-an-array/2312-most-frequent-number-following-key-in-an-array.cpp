class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int, int> frequency;

        for(int index = 1; index < nums.size(); index++){
            if( nums[index - 1] == key){
                frequency[nums[index]]++;
            }
        }
        int maxFrequency = 0;
        int finalResult = 0;

        for(auto element : frequency){
            if(element.second > maxFrequency){
                finalResult = element.first;
                maxFrequency = element.second;
            }
        }
        return finalResult;
    }
};
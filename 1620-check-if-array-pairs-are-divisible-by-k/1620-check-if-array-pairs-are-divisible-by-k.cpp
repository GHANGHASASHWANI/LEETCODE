class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int size = arr.size();

        unordered_map<int, int> valuesFrequency;
        // Step 1: Adding the frequency into the map
        for(int index = 0; index < size; index++){
            int temp = ((arr[index] % k) + k) % k;
            valuesFrequency[temp]++;
        }
        // step 2: Checking the case for the 0 element in map
        if(valuesFrequency.find(0) != valuesFrequency.end()){
            if(valuesFrequency[0] % 2 != 0) return false;
            valuesFrequency.erase(0);
        }
        // Step 2: Iterate in map and check whether the required element present
        for(auto value : valuesFrequency){
            int findKey = k - value.first;
            if(valuesFrequency.find(findKey) == valuesFrequency.end()){
                return false;
            }
            if(valuesFrequency[value.first] != valuesFrequency[findKey]){
                return false;
            }
        }
        return true;
    }
};
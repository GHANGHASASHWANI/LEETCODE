class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> set1;
        set<int> set2;
        // inserting all prefix of arr1 in set1
        for(int i=0;i<arr1.size();i++){
            while(arr1[i]>0){
                set1.insert(arr1[i]);
                arr1[i]/=10;
            }
        }
        // inserting all prefix of arr2 in set2
        for(int i=0;i<arr2.size();i++){
            while(arr2[i]>0){
                set2.insert(arr2[i]);
                arr2[i]/=10;
            }
        }
        // check for same prefix and find length
        int maxi = 0;
        for(auto i : set1){
            if(set2.find(i)!=set2.end()){
                int len =0;
                while(i){
                    len++;
                    i/=10;
                }
                maxi = max(maxi, len); // find the maximum length
            }
        }
        return maxi;
    }
};
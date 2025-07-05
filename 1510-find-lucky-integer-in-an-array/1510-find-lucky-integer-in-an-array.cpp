class Solution {
public:
    int count(vector<int> arr,int k){
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==k) cnt++;
        }
        return cnt;
    }
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        int maxi=-1;
        for(int i=0;i<n;i++){
            int ans=count(arr,arr[i]);
            if(ans==arr[i] && maxi<ans){
                    maxi=ans;
            }
        }
        return maxi;
    }
};
class Solution {
public:

    int getNegIndex(vector<int> &arr){
        int low =0, high = arr.size() - 1, mid = 0;
        int ans = -1;
        while(low <= high){
            mid = low + (high - low)/2;

            if(arr[mid] < 0){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }

    int getPosIndex(vector<int> &arr){
        int low =0, high = arr.size() - 1, mid = 0;
        int ans = -1;
        while(low <= high){
            mid = low + (high - low)/2;

            if(arr[mid] > 0){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }

    int maximumCount(vector<int>& nums) {
        int pos = getPosIndex(nums), neg = getNegIndex(nums);
        if(pos != -1){
            pos = nums.size() - pos;
        }
        cout<<pos<<" "<<neg<<endl;
        if(neg != -1){
            neg = neg + 1;
        }
        if(pos == -1 && neg == -1)return 0;
        return max(pos,neg);
    }
};
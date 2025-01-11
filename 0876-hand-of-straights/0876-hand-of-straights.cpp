class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map< int, int> mpp;

        for(auto i : hand){
            mpp[i]++;
        }

        while(mpp.size() > 0){
            int temp = 0;
            int ele = mpp.begin()->first;
            for(auto i : mpp){
                if(i.first - ele > 1) break;
                else ele = i.first;
                mpp[i.first]--;
                if(mpp[i.first]==0){
                    mpp.erase(i.first);
                }
                temp++;
                if(temp== groupSize){
                    break;
                }
            }
            if(temp != groupSize) return false;
        }
        return true;
    }
};
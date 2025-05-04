class Solution {
private:
    int checkRotation1(vector<int> num1, vector<int> num2, int target){
        int rotate1 = 0, rotate2 = 0;
        for(int i = 0; i < num1.size(); i++){
            if(num1[i] != target && num2[i] != target){
                return 1e8;
            }
            else if(num1[i] != target) rotate1++;
            else if (num2[i] != target) rotate2++;
        }
        return min(rotate1, rotate2);
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans1 = checkRotation1(tops, bottoms, tops[0]);
        int ans2 = checkRotation1(tops, bottoms, bottoms[0]);

        int mini = min(ans1, ans2);

        return mini == 1e8 ? -1 : mini;
    }
};
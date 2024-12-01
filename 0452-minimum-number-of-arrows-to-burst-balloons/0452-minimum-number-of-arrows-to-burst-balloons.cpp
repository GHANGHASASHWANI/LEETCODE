bool cmp(vector<int> &a, vector<int> &b){ return a[0] < b[0];}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int start1 = points[0][0];
        int end1 = points[0][1];
        int ans = 1;

        for(int i = 1 ; i < points.size(); i++){
            if(end1 >= points[i][0]){
                start1 = min(start1, points[i][0]);
                end1 = min(end1, points[i][1]);
            }else{
                start1 = points[i][0];
                end1 = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};
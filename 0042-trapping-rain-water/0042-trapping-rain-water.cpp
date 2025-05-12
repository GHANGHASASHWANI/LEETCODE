class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> preHeight(n, 0);
        preHeight[0] = height[0];

        for (int i = 1; i < height.size(); i++) {
            preHeight[i] = max(preHeight[i-1], height[i]);
        }

        vector<int> postHeight(n, 0);
        postHeight[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            postHeight[i] = max(postHeight[i+1], height[i]);
        }
        int totalWater = 0;

        for (int i = 0; i < height.size(); i++){
            if (height[i] < postHeight[i] && height[i] < preHeight[i]){
                totalWater += min(postHeight[i], preHeight[i]) - height[i];
            }
        }
        return totalWater;
    }
};
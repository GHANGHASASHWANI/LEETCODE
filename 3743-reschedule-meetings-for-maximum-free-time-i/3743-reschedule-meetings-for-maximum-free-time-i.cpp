class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        deque<int> summ;
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);

        int currSum =  0, maxSum = 0;

        for (int i = 0; i < startTime.size(); i++) {
            if (i == 0) {
                summ.push_back(startTime[i]);
                currSum += startTime[i];
                maxSum = max(currSum, maxSum);
            } else {
                if (summ.size() > k) {
                    currSum -= summ.front();
                    summ.pop_front();
                    
                    int diff = startTime[i] - endTime[i - 1];
                    currSum += (diff);
                    summ.push_back(diff);
                    maxSum = max(maxSum, currSum);
                } else {
                    int diff = startTime[i] - endTime[i - 1];
                    currSum += (diff);
                    summ.push_back(diff);
                    maxSum = max(maxSum, currSum);
                }
            }
        }

        return maxSum;
    }
};
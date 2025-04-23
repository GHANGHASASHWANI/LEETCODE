class Solution {
private:
    int findSum(int n){
        int sum = 0;

        while(n > 0){
            sum += (n % 10);
            n /= 10;
        }

        return sum;
    }
public:
    int countLargestGroup(int n) {
        map<int, int> count;

        for (int i = 1; i <= n; i++){
            int digitSum = findSum(i);
            count[digitSum]++;
        }

        int maxFreq = 0;
        for (auto& p : count) {
            maxFreq = max(maxFreq, p.second);
        }

        int maxGroup = 0;
        for (auto& p : count) {
            if (p.second == maxFreq) {
                maxGroup++;
            }
        }
        return maxGroup;

    }
};
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int size = prices.size();
        stack<int> nse;
        vector<int> answer(size, 0);

        for (int i = size - 1; i >= 0; i--) {
            while (!nse.empty() && nse.top() > prices[i])
                nse.pop();
            if (!nse.empty())
                answer[i] = nse.top() * (-1);
            nse.push(prices[i]);
        }
        for (int i = 0; i < prices.size(); i++) {
            answer[i] += prices[i];
        }
        return answer;
    }
};
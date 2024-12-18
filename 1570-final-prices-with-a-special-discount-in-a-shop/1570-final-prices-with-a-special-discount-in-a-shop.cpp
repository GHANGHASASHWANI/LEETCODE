class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int size = prices.size();
        // vector<int> answer(size, 0);

        for(int index = 0; index < size; index ++){
            int value = prices[index];
            for(int indexj = index + 1; indexj < size; indexj++){
                if(prices[indexj] <= value){
                    prices[index]-=prices[indexj];
                    break;
                }
            }
            
        }

        return prices;
    }
};
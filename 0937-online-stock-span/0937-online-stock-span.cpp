class StockSpanner {
public:
    stack<pair<int, int>> stock;
    int ind;
    StockSpanner() {
        ind = -1;
    }
    
    int next(int price) {
        ind += 1;
        int ans  = 0;
        while (!stock.empty() && stock.top().first <= price) {
            stock.pop();
        }
        if (stock.empty()) {
            ans = ind + 1;
        }
        else {
            ans = ind - stock.top().second;
        }
        stock.push({price, ind});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
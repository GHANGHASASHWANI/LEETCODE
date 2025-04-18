class Solution {
public:
    typedef tuple<int, int, int> tupple;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair< int, int>>> adjFlight(n);

        for(auto& flight : flights){
            int flight1 = flight[0];
            int flight2 = flight[1];
            int price = flight[2];

            adjFlight[flight1].push_back({flight2, price});
        }

        queue<tupple> findFlight;
        findFlight.push({0, 0, src});

        vector<int> minPrice(n, INT_MAX);
        minPrice[src] = 0;

        while(not findFlight.empty()){
            auto [currStop, currPrice, currFlight] = findFlight.front();
            findFlight.pop();
            
            if(currStop > k) continue;

            for(auto& neighbor : adjFlight[currFlight]){
                int nextFlight = neighbor.first;
                int nextPrice = neighbor.second;
                if(minPrice[nextFlight] > currPrice + nextPrice){
                    minPrice[nextFlight] = currPrice + nextPrice;
                    findFlight.push({currStop + 1, minPrice[nextFlight], nextFlight});

                }
            }
        }
        return minPrice[dst] == INT_MAX? -1 : minPrice[dst];
    }
};
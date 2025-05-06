class Solution {
public:
    string pushDominoes(string dominoes) {
        map<int, char> mpp;

        for(int i =0; i < dominoes.size(); i++){
            if(dominoes[i] != '.') mpp[i] = dominoes[i];
        }

        vector<pair<int, char>> arr;

        for(auto it : mpp){
            arr.push_back({it.first, it.second});
        }

        for(int i = 1; i < arr.size(); i++){
            if(arr[i].second == 'L' && arr[i - 1].second == 'R'){
                mpp.erase(arr[i].first);
                mpp.erase(arr[i-1].first);
               int q = arr[i].first, p = arr[i-1].first;
                while(p < q){
                    dominoes[p] = 'R';
                    dominoes[q] = 'L';
                    p++;
                    q--;
                }

            }
        }

        for(auto it : mpp){
            int idx = it.first;
            char val = it.second;
            if(val == 'R'){
                idx++;
                while( idx < dominoes.size() && dominoes[idx] == '.' ){
                    dominoes[idx] = 'R';
                    idx++;
                }
            }
            if(val == 'L'){
                idx--;
                while( idx >= 0 && dominoes[idx ] == '.'){
                    dominoes[idx ] = 'L';
                    idx--;
                }
            }
        }
        return dominoes;
    }
};
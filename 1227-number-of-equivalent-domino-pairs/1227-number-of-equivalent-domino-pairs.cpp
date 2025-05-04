class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> freqPairs;
        for (auto num : dominoes){
            int num1 = num[0], num2 = num[1];
            freqPairs[{num1, num2}]++;
        }
        int answer = 0;

        for (int i = 0; i < dominoes.size(); i++){
            int num1 = dominoes[i][0], num2 = dominoes[i][1];
            freqPairs[{num1, num2}]--;
            if(num1 != num2){
                answer += freqPairs[{num1, num2}];
                answer += freqPairs[{num2, num1}];
            }
            else{
               answer += freqPairs[{num1, num2}]; 
            }
        }

        return answer;
    }
};
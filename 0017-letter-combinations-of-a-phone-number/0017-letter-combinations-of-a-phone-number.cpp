class Solution {
public:

    vector<string> answer;

    void f(vector<vector< char >> &numbers, int len,const string &str, int idx){
        if(str.size() == len){
            answer.push_back(str);
            return;
        }
        for(int i =0; i < numbers[idx].size(); i++){
            f(numbers, len, str + numbers[idx][i], idx+1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        map< char, vector< char >> mp;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};

        vector< vector< char >> numbers;
        for(int i =0; i < digits.size(); i++){
            numbers.push_back(mp[digits[i]]);
        }
        f(numbers, digits.size(), "", 0);

        return answer;
    }
};
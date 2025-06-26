class Solution {
private:
    map<string, int> mpp;

    int fn(int i,  int count, string &str, int n) {
        if (i >= str.size()) {
            return 0;
        }
        if (count == n) return 1;

        // string key = to_string(i) + "|" + temp;

        // if (mpp.count(key)) return mpp[key];
        
        int pick = 0, nonPick = 0;

        pick =  fn(i, count + 1, str, n);

        nonPick = fn(i + 1, count, str, n);

        return  pick + nonPick;
    }
public:
    int countVowelStrings(int n) {
        string str = "aeiou";

        return fn(0, 0, str, n);
    }
};
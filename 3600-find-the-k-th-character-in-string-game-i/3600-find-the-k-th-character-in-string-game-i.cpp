class Solution {
public:
    char kthCharacter(int k) {
        string str = "a";

        while (str.size() <= k) {
            string temp = str;

            for (int i = 0; i < temp.size(); i++) {
                if(temp[i] != 'z') temp[i]++;
                else temp[i] = 'a';
            }
            str = str + temp;
            // cout<<str<<endl;
        }
        // cout<<str;
        return str[k - 1];
    }
};
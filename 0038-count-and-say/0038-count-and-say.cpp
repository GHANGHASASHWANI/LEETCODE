class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string str=countAndSay(n-1);

        string res="";
        int cnt=1;
        for(int i=1;i<str.size();i++){
            if(str[i]==str[i-1]) cnt++;
            else{
                res+=(to_string(cnt)+str[i-1]);
                cnt=1;
            }
        }
        res+=(to_string(cnt)+str[str.size()-1]);
        return res;
    }
};
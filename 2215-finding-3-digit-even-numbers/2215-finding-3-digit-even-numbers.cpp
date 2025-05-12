class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        map<int,int> prev;
        vector<int> ans;
        for(int i=0;i<digits.size();i++){
            prev[digits[i]]++;
        }

        for(int i=100;i<1000;i+=2){
           int n=i;
           int a=n%10;
           n/=10;
           int b=n%10;
           n/=10;
           int c=n;

           if(prev.find(a)!=prev.end()  && prev[a]>0){
            prev[a]--;
            if(prev.find(b)!=prev.end() && prev[b]>0){
                prev[b]--;
                if(prev.find(c)!=prev.end() && prev[c]>0) ans.push_back(i);
                prev[b]++;
            }
            prev[a]++;
           }
        }
        return ans;
    }
};
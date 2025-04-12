class Solution {
private:
    set< string > dp;
    int fact[10] = {1, 2, 6, 24, 120, 720, 5040,40320, 362880, 3628800, };
    long long ways(string str){
        // cout<<str<<endl;
        map< char, int > mpp;
        int zero = 0;
        for(auto i : str){
            mpp[i]++;
            if(i == '0') zero++;
        }
        long long divide = 1;
        for(auto i : mpp){
            // cout<<i.first<<" "<<i.second<<endl;
            divide *= fact[i.second - 1];
        }
        int ans = 0;
        int n = str.size();

        ans = (fact[n-1] - zero * fact[max(n-2, 0)])/ divide;
        return ans;
    }

    int length;
    long long fn(int i, int j, int k, string &str){
        if(i > j){
            long long num = stoll(str);
            
            if(num == 0) return 0;
            int len = log10(num)+1;
            // cout<<num<<" "<<len<<endl;
            if(num % k == 0 && len == length){
                // cout<<num<<endl;
                // return 1;
                string temp = str;
                sort(temp.begin(), temp.end());
                if(dp.find(temp) != dp.end()) return 0;
                dp.insert(temp);
                return ways(temp);

            }
            return 0;
        }

        long long ans = 0;
        for(int idx = 0; idx <= 9; idx++){
            str[i] = idx + '0';
            str[j] = idx + '0';
            ans += fn(i+1, j-1, k, str);
        }
        return ans;
    }
public:
    long long countGoodIntegers(int n, int k) {
        length = n;
        string str;
        for(int i =0; i < n; i++) str += '-1';
        // cout<<str<<endl;
        return fn(0, n-1, k, str);

    }
};
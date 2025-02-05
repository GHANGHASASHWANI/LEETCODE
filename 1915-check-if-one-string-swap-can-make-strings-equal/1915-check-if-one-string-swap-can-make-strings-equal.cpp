class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        map< char, int > mp1;
        map< char, int> mp2;

        for(auto i : s1){
            mp1[i]++;
        }
        for(auto i : s2){
            mp2[i]++;
        }
        if(mp1 != mp2) return false;
        int ans = 0;
        for(int i =0; i < s1.size(); i++){
            if(s1[i] != s2[i]) ans++;
        }
        ans = ceil(ans * 1.0/2.0);
      
        return ans == 1;
    }
};
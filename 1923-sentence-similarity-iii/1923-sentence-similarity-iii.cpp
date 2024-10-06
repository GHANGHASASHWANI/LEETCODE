class Solution {
private:
    vector<string> fill(string& s){
        vector<string> v;
        stringstream ss(s);
        string word;
        while(ss>>word){
            v.push_back(word);
        }
        ss.clear();
        return v;
    }
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size() > s2.size()) return areSentencesSimilar(s2, s1);
        vector<string> v1 = fill(s1), v2 = fill(s2);
        int n1 = v1.size(), n2 = v2.size();
        
        int l = 0, r1 = n1-1, r2 = n2-1;
        while(l < n1 && v1[l] == v2[l]){
            l++;
        }
        while(r1 >= 0 && v1[r1] == v2[r2]){
            r1--;
            r2--;
        }

        return r1 < l;
    }
};
auto speedup = [](){ios::sync_with_stdio(0); cin.tie(0); return 0; }();
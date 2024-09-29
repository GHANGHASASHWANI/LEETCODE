class AllOne {
public:
unordered_map<string,int> values;
set<pair<int, string>> se;
    AllOne() {
        values.clear();
    }
    
    void inc(string key) {
        int n = values[key];
        se.erase({n,key});
        se.insert({n+1,key});
        values[key]++;
    }
    
    void dec(string key) {
        int n = values[key];
        values[key]--;
        se.erase({n,key});
        if(values[key]>0) se.insert({n-1,key});
        else values.erase(key);
    }
    
    string getMaxKey() {
        string ans = "";
        if(!se.empty()) return se.rbegin()->second;
        return ans;
    }
    
    string getMinKey() {
        string ans = "";
        if(!se.empty()) return se.begin()->second;
        return ans;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
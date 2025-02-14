class ProductOfNumbers {
public:
    vector< int > v;
    ProductOfNumbers() {
        v.clear();
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        int ans = 1;
        for(int i = v.size() - 1; i >=0 && k--; i--){
            ans*= v[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
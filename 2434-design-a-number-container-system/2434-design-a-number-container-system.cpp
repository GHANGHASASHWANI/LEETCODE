class NumberContainers {
public:
map< int, set<int>> number1;
map< int, int > index1;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(index1.find(index) != index1.end()){
            int prev = index1[index];
            number1[prev].erase(index);

            if(number1[prev].empty()){
                number1.erase(prev);
            }
        }
        index1[index] = number;
        number1[number].insert(index);
    }
    
    int find(int number) {
        if(number1.find(number) != number1.end()){
            return *number1[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
class MyCalendar {
public:
  vector<pair<int, int>> bookings;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
         for (auto& event : bookings) {
            int existingStart = event.first;
            int existingEnd = event.second;
            if (start < existingEnd && end > existingStart) {
                return false;
            }
        }
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
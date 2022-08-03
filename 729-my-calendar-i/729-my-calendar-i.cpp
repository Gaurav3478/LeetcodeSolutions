class MyCalendar {
public:
    set<pair<int, int>> s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = s.upper_bound({start, end});
        if(it != s.end()) {
            if((*it).first < end) {
                return false;
            }
        }
        if(it != s.begin()) {
            it--;
            if(start < (*it).second) {
                return false;
            }
        }
        s.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
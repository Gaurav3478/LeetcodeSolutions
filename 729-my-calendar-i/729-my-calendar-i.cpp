class MyCalendar {
public:
    vector<pair<int, int>> calendar;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0; i<calendar.size(); i++) {
            int st = calendar[i].first, e = calendar[i].second;
            if(start < e && start >= st || end > st && end <= e || st < end && st >= start || e > start && e <= end) {
                // cout << start << " " << end << endl;
                // cout << st << " " << e << endl;
                return false;
            }  
        }
        calendar.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
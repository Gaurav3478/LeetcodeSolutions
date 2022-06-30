class ExamRoom {
public:
    set<int> s;
    int n;
    ExamRoom(int n) {
        this->n = n;
    }
    
    int seat() {
        if(s.size() == 0) {
            s.insert(0);
            return 0;
        }
        int idx = -1;
        int dist = 0;
        int prev = -1;
        //we're going to iterate over the set of taken elements and work accordingly
        for(auto it: s) {
            if(it == *s.begin()) {
                if(dist < it) {
                    dist = it;
                    idx = 0;
                }
                prev = it;
            }
            else {
                if(dist < (it - prev)/2) {
                    dist = (it - prev)/2;
                    idx = prev + dist;
                }
                prev = it;
            }
        }
        if(n-1 - prev > dist) {
            dist = n-1-prev;
            idx = n-1;
        }
        s.insert(idx);
        return idx;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
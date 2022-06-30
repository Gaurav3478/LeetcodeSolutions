class MyHashSet {
public:
    vector<bool> hs;
    MyHashSet() {
        hs = vector<bool>(1e6 + 1, false);
    }
    
    void add(int key) {
        hs[key] = true;
    }
    
    void remove(int key) {
        hs[key] = false;
    }
    
    bool contains(int key) {
        return hs[key]==true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
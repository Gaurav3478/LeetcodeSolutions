class MyHashSet {
private:
    int numBuckets;
    vector<vector<int>> buckets;
public:
    MyHashSet() {
        numBuckets = 15000;
        buckets = vector<vector<int>>(numBuckets);
    }
    
    void add(int key) {
        int bucket = key%numBuckets;
        buckets[bucket].push_back(key);
    }
    
    void remove(int key) {
        int bucket = key%numBuckets;
        buckets[bucket].erase(std::remove(buckets[bucket].begin(), buckets[bucket].end(), key), buckets[bucket].end());
        // vec.erase(std::remove(vec.begin(), vec.end(), 8), vec.end());
    }
    
    bool contains(int key) {
        int bucket = key%numBuckets;
        for(int i=0; i<buckets[bucket].size(); i++) {
            if(buckets[bucket][i] == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
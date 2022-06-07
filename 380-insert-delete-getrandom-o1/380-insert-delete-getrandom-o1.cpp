class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> vect;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()) {
            vect.push_back(val);
            mp[val] = vect.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        auto it = mp.find(val);
        if(it == mp.end()) {
            return false;
        }
        int x = vect.back();
        mp[x] = mp[val];
        vect[mp[x]] = x;
        vect.pop_back();
        mp.erase(it);
        return true;
    }
    
    int getRandom() {
        return vect[rand()%vect.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
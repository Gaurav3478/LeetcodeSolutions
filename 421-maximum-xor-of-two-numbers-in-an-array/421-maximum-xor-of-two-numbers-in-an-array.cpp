class Node {
public:
    Node *links[2];
    
    bool containsKey(int ind) {
        return links[ind] != NULL;
    }
    Node *get(int ind) {
        return links[ind];
    }
    void put(int ind, Node *node) {
        links[ind] = node;
    }
};

class Trie {
private:
    Node *root;
public: 
    Trie() {
        root = new Node();
    }
    void insert(int ind) {
        Node *node = root;
        for(int i=31; i>=0; i--) {
            int bit = (ind>>i)&1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int findMax(int num) {
        int ans = 0;
        Node *node = root;
        for(int i=31; i>=0; i--) {
            int bit = (num>>i)&1;
            if(node->containsKey(!bit)) {
                node = node->get(!bit);
                ans += 1<<i;
            }
            else {
                node = node->get(bit);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            trie.insert(nums[i]);
        }
        for(int i=0; i<n; i++) {
            ans = max(ans, trie.findMax(nums[i]));
        }
        return ans;
    }
};
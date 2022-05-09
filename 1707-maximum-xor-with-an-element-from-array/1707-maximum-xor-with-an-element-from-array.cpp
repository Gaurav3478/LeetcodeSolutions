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

    bool cmp(vector<int> v1, vector<int> v2) {
        return v1[1] < v2[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        //sort in ascending order of ai
        Trie trie;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<pair<int, pair<int, int>>> p;
        for(int i=0; i<queries.size(); i++) {
            p.push_back({queries[i][1], {queries[i][0], i}});
        }
        //now we'll sort nums on the basis of it's second value
        sort(p.begin(), p.end());
        vector<int> ans(queries.size());
        int index = 0;
        for(int i=0; i<queries.size(); i++) {
            int ai = p[i].first;
            int xi = p[i].second.first;
            int qInd = p[i].second.second;
            while(index < n && nums[index] <= ai) {
                trie.insert(nums[index]);
                index++;
            }
            if(index == 0) {
                ans[qInd] = -1;
            }
            else {
                ans[qInd] = trie.findMax(xi);
            }
        }
        return ans;
    }
};
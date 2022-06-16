/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

unordered_map<Node*, Node*> mp;
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) // if node is null, then simply return null
        {
            return NULL;
        }
        if(mp.find(node) == mp.end()) {
            mp[node] = new Node(node->val, {});
            for(auto x: node->neighbors) {
                mp[node]->neighbors.push_back(cloneGraph(x));
            }
        }
        return mp[node];
    }
};
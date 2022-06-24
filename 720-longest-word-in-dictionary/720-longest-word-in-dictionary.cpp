class Node {
    public:
    Node *links[26];
    bool flag = false;
    
    bool containsKey(char ch) {
        return links[ch-'a'] != NULL;
    }
    
    void put(char ch, Node *node) {
        links[ch-'a'] = node;
    }
    
    Node *get(char ch) {
        return links[ch-'a'];
    }
    
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};

class Trie {
    private:
        Node *root;    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i=0; i<prefix.size(); i++) {
            if(!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie *t = new Trie();
        sort(words.begin(), words.end());
        int n = words.size();
        int maxLen = 0;
        string ans = "";
        for(int i=0; i<n; i++) {
            bool ok = true;
            string cur = "";
            for(int j=0; j<words[i].size()-1; j++) {
                cur += words[i][j];
                if(!t->startsWith(cur)) {
                    ok = false;
                }
            }    
            if(ok) {
                t->insert(words[i]);
            }
            if(ok && words[i].size() > maxLen) {
                ans = words[i];
                maxLen = words[i].size();
            }
        }
        return ans;
    }
};
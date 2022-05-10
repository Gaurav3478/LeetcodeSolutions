class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else {
                if(st.empty()) {
                    return false;
                }
            if(s[i] == ')') {
                if(st.top() != '(') {
                    return false;
                }
                st.pop();
            }
            else if(s[i] == '}') {
                if(st.top() != '{') {
                    return false;
                }
                st.pop();
            }
            else if(s[i] == ']') {
                if(st.top() != '[') {
                    return false;
                }
                st.pop();
            }
            }
            
        }
        if(!st.empty()) {
            return false;
        }
        return true;
    }
};
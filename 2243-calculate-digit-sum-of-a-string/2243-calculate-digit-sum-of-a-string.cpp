class Solution {
public:
    string digitSum(string s, int k) {
        int cnt = 0;
        int sum = 0;
        string temp = "";
        while(s.size() > k) {
            cnt = 0;
            temp = "";
            for(int i=0; i<s.size(); i++) {
                cnt++;
                sum += s[i]-'0';
                if(cnt == k) {
                    cnt = 0;
                    temp += to_string(sum);
                    sum = 0;
                }
            }
            if(cnt!=0) {
                temp+=to_string(sum);
                sum = 0;
            }
            s = temp;
        } 
        return s;   
    }
};
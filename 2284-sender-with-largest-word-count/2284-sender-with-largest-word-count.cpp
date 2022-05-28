class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
    unordered_map<string, int> cnt;
    string res;
    int max_cnt = 0;
    for (int i = 0; i < messages.size(); ++i) {
        int words = count(begin(messages[i]), end(messages[i]), ' ') + 1;
        int total = cnt[senders[i]] += words;
        if (total > max_cnt || (total == max_cnt && senders[i] > res)) {
            max_cnt = total;
            res = senders[i];
        }
    }
    return res;
}
};
class Solution {
public:
    bool worddif(string &s1,string &s2)
    {
        if(s1.length()!=s2.length())
        {
            return false;
        }
        int c=0;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i])
            {
                c++;
            }
        }
        return c==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        map<string,int> vis;
        int ans=INT_MAX;
        while(!q.empty())
        {
            string s=q.front().first;
            int l=q.front().second;
            q.pop();
            for(int i=0;i<wordList.size();i++)
            {
                if(worddif(s,wordList[i]) && vis[wordList[i]]==0)
                {
                    q.push({wordList[i],l+1});
                    if(wordList[i]==endWord)
                    {
                        ans=min(ans,l+1);
                        break;
                    }
                    vis[wordList[i]]++;
                }
            }
        }
        return ans==INT_MAX?0:ans;
    }
};
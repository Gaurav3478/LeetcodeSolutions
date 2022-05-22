class Solution {
public:
    int minimumLines(vector<vector<int>>& st) {
         sort(st.begin(),st.end());
        
        long double m=INT_MIN;
        int ans=0;
        for(int i=0;i<st.size()-1;i++)
        {
            long double x=(st[i+1][0]-st[i][0]);
            long double y=(st[i+1][1]-st[i][1]);
            
            long double p=y/x;
            if(p!=m)
            {
                m=p;
                ans++; 
            }
        }
        return ans;
        
    }
};
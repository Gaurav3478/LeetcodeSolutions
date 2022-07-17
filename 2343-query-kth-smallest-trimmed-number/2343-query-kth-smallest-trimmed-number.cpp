class Solution {
public:
    
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        
        vector<pair<string,int >>v;
        
        vector<int >ans;
        
        
        for( int  i=0; i<q.size() ; i++){
            
             v.clear();
            
            int  len = q[i][1];
            int  idx = q[i][0];
            int  cnt=0;
            
            for( auto i : nums){
           
                int leng=i.length();
            
                                
                v.push_back({i.substr(leng-len,len),cnt++});
                
            }
            
          
            sort(v.begin(),v.end());
            
            ans.push_back(v[idx-1].second);
            
            
        }
        
        return ans;
        
        
    }
};
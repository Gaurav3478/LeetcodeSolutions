const int MOD = 1e9 + 7;

class Solution {
public:
    int binpow(long long int a, long long int b, long long int m) {
    a %= m;
    long long int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
    }   
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        auto getProduct = [&](int n) -> vector<int> {
            vector<int> vect;
            int n_cpy = n;
            while(n_cpy > 0) {
                if(n_cpy % 2) {
                    vect.push_back(1);
                }
                else {
                    vect.push_back(0);
                }
                n_cpy /= 2;
            }
            return vect;
        };
        
        vector<int> vect = getProduct(n);
        reverse(vect.begin(), vect.end());
        vector<int> prods;
        for(int i=0; i<vect.size(); i++) {
            if(vect[i] == 1) {
                prods.push_back(1 << (vect.size() - i - 1));
            }
        }
        
        reverse(prods.begin(), prods.end());
        int m = prods.size();
        vector<long long int> pref(m + 1, 1);
        for(int i=0; i<m; i++) {
            pref[i + 1] = (pref[i]*prods[i])%MOD;
        }
        vector<int> ans;
        for(int qq=0; qq<queries.size(); qq++) {
            int l = queries[qq][0];
            int r = queries[qq][1];
            ans.push_back((pref[r + 1]*binpow(pref[l], MOD - 2, MOD))%MOD);
        }
        return ans;
    }
};
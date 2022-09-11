template<typename T>
class segtree {
    public:
    vector<T> t;
    int n;
    T def;
    function<T(T, T)> fx;
    void build(int _n, T _def, function<T(T, T)> _fx) {
        n = _n, def = _def, fx = _fx;
        t.assign(n * 2, def);
        for(int i = n - 1; i; i--) t[i] = fx(t[i * 2], t[i * 2 + 1]);
    }
    void build(vector<T>& a, T _def, function<T(T, T)> _fx) {
        n = sz(a), def = _def, fx = _fx;
        t.assign(n * 2, def);
        for(int i = 0; i < n; i++) t[i + n] = a[i];
        for(int i = n - 1; i; i--) t[i] = fx(t[i * 2], t[i * 2 + 1]);
    }
    void update(int i, T v) {
        for(t[i += n] = v; i > 1; ) {
            i /= 2;
            t[i] = fx(t[i * 2], t[i * 2 + 1]);
        }
    }
    // this query is made on [l, r)
    T query(int l, int r) {
        T lans = def, rans = def;
        for(l += n, r += n; l < r; l /= 2, r /= 2) {
            if(l % 2) lans = fx(lans, t[l++]);
            if(r % 2) rans = fx(t[--r], rans);
        }
        return fx(lans, rans);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        segtree<int> seg;
        int n = nums.size();
        seg.build(2e5 + 11, 0, [&] (int a, int b) {
            return max(a, b);
        });
        int ans = 0;
        for(int i=0; i<n; i++) {
            int num = nums[i];
            int val = 1 + seg.query(max(num - k, 1), max(num, 1));
            seg.update(num, val);
            ans = max(ans, val);
        }
        return ans;
    }
};
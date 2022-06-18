class Solution 
{
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) 
    {
        std::vector<std::vector<int>> res;
        
        auto comp = [](const std::pair<int, int>& a, const std::pair<int, int>& b)
        {
            return (a.first + a.second) < (b.first + b.second);
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> Q(comp);
        
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                int sum = a[i] + b[j];
                if (Q.size() < k)
                {
                    Q.push({a[i], b[j]});
                }
                else if (sum < Q.top().first + Q.top().second)
                {
                        Q.pop();
                        Q.push({a[i], b[j]});
                }
                else
                {
                    break;
                }
            }
        }
        
        while (!Q.empty())
        {
            std::pair<int, int> p = Q.top();
            res.push_back({p.first, p.second});
            Q.pop();
        }
        return res;
    }
};
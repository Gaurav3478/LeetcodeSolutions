class Solution {
public:
    string solve(string &pri,int discount){
        long int price = stol(pri);
        pri = "";
        double ans = price - ((double)price/100)*discount;
        ostringstream out;
        out.precision(2);
        out << std::fixed << ans;
        return out.str();
    }
    string discountPrices(string nums, int discount) {
        string ans = "", num = "";
        for(int i=0;i<nums.size();i++){
            if(nums[i] == '$' && (i==0 || nums[i-1]==' ')){
                num = "";
                ans += nums[i];
                int j = i+1;
                if(j >= nums.size()) return ans;
                while(j<nums.size() && isdigit(nums[j])){
                    num += nums[j];
                    j++;
                }
                if(j>=nums.size() || (nums[j] == ' ' && num.size())){
                    string val = solve(num,discount);
                    ans += val;
                }else{
                    ans += num;
                }
                i = j-1;
            }else{
                ans += nums[i];
            }
        }
        return ans;
    }
};
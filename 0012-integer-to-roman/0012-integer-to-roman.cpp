class Solution {
public:
    string intToRoman(int num) {
        vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
        vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C"};
        vector<string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M"};
        vector<string> thousands = {"", "M", "MM", "MMM"};
        string ans = thousands[num/1000] + hundreds[(num/100)%10] + tens[(num/10)%10] + ones[(num/1)%10];
        return ans;
    }
};
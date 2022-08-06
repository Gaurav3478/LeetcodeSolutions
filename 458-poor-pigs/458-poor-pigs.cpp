class Solution {
public:
    /*
    4 15 15 
    2 pigs needed, give first pig (1, 2), second pig(2, 3)
    */
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log(buckets)/log(minutesToTest/minutesToDie+1));        
    }
};
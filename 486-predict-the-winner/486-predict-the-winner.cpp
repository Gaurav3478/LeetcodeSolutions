class Solution {
    bool checkWin(int ans,int total){
	   //ans=max player 1 can score and total=sum of all elements in the array
	   //so, player2's score=total-player1's score . ie:-total-ans;
	   //According to question player1's score should be greater than or equal to player2's score. 
	   return ans>=total-ans;
    }
    int maxScore(vector<int>&A,int total,int i,int j){
        if(i>j) //our base condition
            return 0;
      return total-min(maxScore(A,total-A[i],i+1,j),maxScore(A,total-A[j],i,j-1)); //max the current player can get is total-maxm the next player can get.
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int total=0; 
		//total=sum of all elements in the array
        for(auto x:nums)
            total+=x;
        return checkWin(maxScore(nums,total,0,nums.size()-1),total);
    }
};
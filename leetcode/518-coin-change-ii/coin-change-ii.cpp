class Solution {
    int rec(vector<int>& coins,int amount,int i,vector<vector<int>>&dp){
        if(i==coins.size()){
            return 0;
        }
        if(amount==0){
            return 1;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int take=0;
        if(amount>=coins[i]){
            take=rec(coins,amount-coins[i],i,dp);
        }
        int notTake=rec(coins,amount,i+1,dp);
        return dp[i][amount]=take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans=rec(coins,amount,0,dp);
        return ans;
    }
};
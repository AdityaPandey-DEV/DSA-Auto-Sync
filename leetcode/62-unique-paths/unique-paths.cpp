class Solution {
    int rec(int m, int n,vector<vector<int>>&dp){
        if(m<0||n<0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(m==0&&n==0){
            return 1;
        }
        return dp[m][n]=rec(m-1,n,dp)+rec(m,n-1,dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return rec(m-1,n-1,dp);
    }
};
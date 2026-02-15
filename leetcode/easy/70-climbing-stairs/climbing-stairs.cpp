class Solution {
  int rec(int n, vector<int>& dp) {
    if (n < 0) {
      return 0;
    }
    if (n == 0) {
      return 1;
    }
    if (dp[n] != -1) {
      return dp[n];
    }

    return dp[n] = rec(n - 1, dp) + rec(n - 2, dp);
  }

 public:
  int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return rec(n, dp);
  }
};
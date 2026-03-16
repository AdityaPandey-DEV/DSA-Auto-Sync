class Solution {
  int rec(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
    if (i == coins.size()) {
      return INT_MAX;
    }
    if (amount == 0) {
      return 0;
    }
    if (dp[i][amount] != -1) {
      return dp[i][amount];
    }
    int take = INT_MAX;
    if (amount >= coins[i]) {
      take = rec(coins, amount - coins[i], i, dp);
      if (take != INT_MAX) take += 1;
    }
    int notTake = rec(coins, amount, i + 1, dp);
    return dp[i][amount] = min(take, notTake);
  }

 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
    int ans = rec(coins, amount, 0, dp);
    if (ans == INT_MAX) return -1;
    return ans;
  }
};
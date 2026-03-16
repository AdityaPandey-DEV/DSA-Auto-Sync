class Solution {
 public:
  int rec(vector<int>& nums, int n, vector<int>& dp) {
    if (n < 0) {
      return 0;
    }
    if (dp[n] != -1) {
      return dp[n];
    }
    int take = nums[n] + rec(nums, n - 2, dp);
    int notTake = rec(nums, n - 1, dp);

    return dp[n] = max(take, notTake);
  }
  int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    int ans = rec(nums, n - 1, dp);
    return ans;
  }
};
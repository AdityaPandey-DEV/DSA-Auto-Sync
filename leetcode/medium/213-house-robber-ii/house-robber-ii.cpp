class Solution {
 public:
  int rec(vector<int>& nums, int n, int start, vector<int>& dp) {
    if (n < start) {
      return 0;
    }
    if (dp[n] != -1) {
      return dp[n];
    }
    int take = nums[n] + rec(nums, n - 2, start, dp);
    int notTake = rec(nums, n - 1, start, dp);

    return dp[n] = max(take, notTake);
  }
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    vector<int> dp1(n, -1);
    int take = rec(nums, n - 2, 0, dp1);
    vector<int> dp2(n, -1);
    int notTake = rec(nums, n - 1, 1, dp2);
    return max(take, notTake);
  }
};
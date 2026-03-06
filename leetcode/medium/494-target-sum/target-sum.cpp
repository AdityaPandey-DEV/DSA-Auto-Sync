class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int total = 0;

        for(int x : nums) total += x;

        vector<vector<int>> dp(n+1, vector<int>(2*total+1, 0));

        int offset = total;

        dp[0][offset] = 1;

        for(int i = 0; i < n; i++) {

            for(int sum = -total; sum <= total; sum++) {

                if(dp[i][sum + offset] != 0) {

                    dp[i+1][sum + nums[i] + offset] += dp[i][sum + offset];

                    dp[i+1][sum - nums[i] + offset] += dp[i][sum + offset];
                }
            }
        }

        return (target > total || target < -total) ? 0 : dp[n][target+offset];
    }
};
class Solution {
  int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
    // base cases FIRST
    if (i < 0 && j < 0) return 0;
    if (i < 0) return s2[j] + solve(s1, s2, i, j - 1, dp);
    if (j < 0) return s1[i] + solve(s1, s2, i - 1, j, dp);

    // dp check (safe now)
    if (dp[i][j] != -1) return dp[i][j];

    // matching characters
    if (s1[i] == s2[j]) {
      return dp[i][j] = solve(s1, s2, i - 1, j - 1, dp);
    }

    // delete from either side
    return dp[i][j] = min(s1[i] + solve(s1, s2, i - 1, j, dp),
                          s2[j] + solve(s1, s2, i, j - 1, dp));
  }

 public:
  int minimumDeleteSum(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(s1, s2, n - 1, m - 1, dp);
  }
};
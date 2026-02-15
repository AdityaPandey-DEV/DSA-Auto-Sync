class Solution {
public:
  double rec(int i, int j, vector<vector<double>> &dp) {
    if (j < 0 || j > i) {
      return 0.0;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    double leftSide = max(0.0, (rec(i - 1, j - 1, dp) - 1.0) / 2.0);
    double rightSide = max(0.0, (rec(i - 1, j, dp) - 1.0) / 2.0);

    return dp[i][j] = leftSide + rightSide;
  }

  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1, -1));
    dp[0][0] = poured;
    return min(1.0, rec(query_row, query_glass, dp));
  }
};
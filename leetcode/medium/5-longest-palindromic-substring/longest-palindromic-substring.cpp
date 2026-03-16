class Solution {
 public:
  bool isPal(int i, int j, string &s, vector<vector<int>> &dp) {
    if (i >= j) return true;

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] != s[j]) return dp[i][j] = false;

    return dp[i][j] = isPal(i + 1, j - 1, s, dp);
  }

  string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (isPal(i, j, s, dp)) {
          if (j - i + 1 > maxLen) {
            maxLen = j - i + 1;
            start = i;
          }
        }
      }
    }

    return s.substr(start, maxLen);
  }
};
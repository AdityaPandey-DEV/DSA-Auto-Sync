class Solution {
 public:
  int mini(string word1, string word2, vector<vector<int>>& dp, int n1,
           int n2) {
    if (n1 <= 0) return n2;
    if (n2 <= 0) return n1;
    if (dp[n1][n2] != -1) return dp[n1][n2];
    if (word1[n1 - 1] == word2[n2 - 1]) {
      return dp[n1][n2] = mini(word1, word2, dp, n1 - 1, n2 - 1);
    }
    return dp[n1][n2] = 1 + min(mini(word1, word2, dp, n1 - 1, n2 - 1),
                                min(mini(word1, word2, dp, n1, n2 - 1),
                                    mini(word1, word2, dp, n1 - 1, n2)));
  }
  int minDistance(string word1, string word2) {
    int n1 = word1.length();
    int n2 = word2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
    return mini(word1, word2, dp, n1, n2);
  }
};
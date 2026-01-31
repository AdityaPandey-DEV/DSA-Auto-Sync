class Solution {
  int subSeq(vector<int>& a, vector<int>& b, int i, int j,
             vector<vector<int>>& dp) {
    if (i == a.size() || j == b.size()) return INT_MIN;

    if (dp[i][j] != INT_MIN) return dp[i][j];

    int prod = a[i] * b[j];
    int next = subSeq(a, b, i + 1, j + 1, dp);

    int take = prod + max(0, next);
    int skipA = subSeq(a, b, i + 1, j, dp);
    int skipB = subSeq(a, b, i, j + 1, dp);

    return dp[i][j] = max({take, skipA, skipB});
  }

 public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
    return subSeq(nums1, nums2, 0, 0, dp);
  }
};
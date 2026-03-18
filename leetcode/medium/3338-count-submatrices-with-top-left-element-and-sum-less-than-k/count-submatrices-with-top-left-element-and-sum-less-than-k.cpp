class Solution {
 public:
  int countSubmatrices(vector<vector<int>>& grid, int k) {
    vector<vector<int>> arr = grid;
    int n = arr.size();
    int m = arr[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i > 0) {
          arr[i][j] += arr[i - 1][j];
        }
        if (j > 0) {
          arr[i][j] += arr[i][j - 1];
        }
        if (i > 0 && j > 0) {
          arr[i][j] -= arr[i - 1][j - 1];
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (arr[i][j] <= k) {
          ans++;
        }
      }
    }
    return ans;
  }
};
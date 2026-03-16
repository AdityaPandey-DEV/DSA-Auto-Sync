class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    vector<pair<int, int>> p;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == 0) {
          p.push_back({i, j});
        }
      }
    }
    for (int k = 0; k < p.size(); k++) {
      int i = p[k].first;
      int j = p[k].second;
      for (int a = 0; a < matrix.size(); a++) {
        matrix[a][j] = 0;
      }
      for (int a = 0; a < matrix[0].size(); a++) {
        matrix[i][a] = 0;
      }
    }
  }
};
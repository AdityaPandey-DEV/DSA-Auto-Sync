class Solution {
  int n, m;
  int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  bool dfs(vector<vector<char>>& board, int i, int j, string word, int k) {
    if (k == word.size()) return true;
    int n = board.size();
    int m = board[0].size();

    if (i < 0 || i >= n || j < 0 || j >= m) {
      return false;
    }
    char ch = board[i][j];

    if (board[i][j] == '$' || board[i][j] != word[k]) {
      return false;
    }
    bool res = false;
    if (word[k] == board[i][j]) {
      board[i][j] = '$';
      for (auto d : dir) {
        if (dfs(board, i + d[0], j + d[1], word, k + 1)) {
          res = true;
        }
      }
    }
    board[i][j] = ch;
    return res;
  }

 public:
  bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    bool res = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (dfs(board, i, j, word, 0)) {
          res = true;
        }
      }
    }
    return res;
  }
};
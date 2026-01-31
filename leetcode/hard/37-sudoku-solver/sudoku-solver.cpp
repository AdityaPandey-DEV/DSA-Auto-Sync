class Solution {
 public:
  bool checkH(vector<vector<char>>& board, int n, char d) {
    for (int i = 0; i < 9; i++) {
      if (board[n][i] == d) return false;
    }
    return true;
  }
  bool checkV(vector<vector<char>>& board, int m, char d) {
    for (int i = 0; i < 9; i++) {
      if (board[i][m] == d) return false;
    }
    return true;
  }
  bool checkG(vector<vector<char>>& board, int n, int m, char d) {
    int sr, sc;
    sr = (n / 3) * 3;
    sc = (m / 3) * 3;

    for (int i = sr; i <= sr + 2; i++) {
      for (int j = sc; j <= sc + 2; j++) {
        if (board[i][j] == d) {
          return false;
        }
      }
    }
    return true;
  }
  bool isSafe(vector<vector<char>>& board, int n, int m, char d) {
    return (checkH(board, n, d) && checkV(board, m, d) &&
            checkG(board, n, m, d));
  }
  bool ss(vector<vector<char>>& board, int n, int m) {
    if (n == 9) {
      return true;
    }
    int nextn = n;
    int nextm = m + 1;
    if (nextm == 9) {
      nextn = nextn + 1;
      nextm = 0;
    }

    if (board[n][m] != '.') {
      return ss(board, nextn, nextm);
    }
    for (char d = '1'; d <= '9'; d++) {
      if (isSafe(board, n, m, d)) {
        board[n][m] = d;
        if (ss(board, nextn, nextm)) {
          return true;
        }
        board[n][m] = '.';
      }
    }
    return false;
  }
  void solveSudoku(vector<vector<char>>& board) { ss(board, 0, 0); }
};
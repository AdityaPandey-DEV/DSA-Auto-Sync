class Solution {
  bool bfs(vector<vector<int>>& world) {
    int row = world.size();
    int col = world[0].size();

    queue<pair<int, int>> q;
    vector<vector<bool>> vis(row, vector<bool>(col, false));

    for (int j = 0; j < col; j++) {
      if (world[0][j] == 1) {
        q.push({0, j});
        vis[0][j] = true;
      }
    }

    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();

      if (r == row - 1) return true;

      for (auto& d : dir) {
        int nr = r + d[0];
        int nc = c + d[1];

        if (nr >= 0 && nr < row && nc >= 0 && nc < col && !vis[nr][nc] &&
            world[nr][nc] == 1) {
          vis[nr][nc] = true;
          q.push({nr, nc});
        }
      }
    }
    return false;
  }

  bool check(int day, int row, int col, vector<vector<int>>& cells) {
    vector<vector<int>> world(row, vector<int>(col, 1));

    for (int i = 0; i < day; i++) {
      int x = cells[i][0] - 1;
      int y = cells[i][1] - 1;
      world[x][y] = 0;
    }

    return bfs(world);
  }

 public:
  int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    int left = 0;
    int right = cells.size();
    int ans = 0;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (check(mid, row, col, cells)) {
        ans = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return ans;
  }
};
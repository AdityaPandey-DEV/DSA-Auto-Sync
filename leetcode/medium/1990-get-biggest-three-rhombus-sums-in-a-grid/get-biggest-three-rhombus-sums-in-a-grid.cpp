class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> d1(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> d2(m + 1, vector<int>(n + 2, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                d1[i][j] = grid[i - 1][j - 1] + d1[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= 1; j--) {
                d2[i][j] = grid[i - 1][j - 1] + d2[i - 1][j + 1];
            }
        }

        set<int> s;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                s.insert(grid[i][j]);

                for (int k = 1;; k++) {

                    int top_r = i - k;
                    int bottom_r = i + k;
                    int left_c = j - k;
                    int right_c = j + k;

                    if (top_r < 0 || bottom_r >= m || left_c < 0 ||
                        right_c >= n)
                        break;

                    int sum = 0;

                    sum += d1[i + 1][right_c + 1] - d1[top_r][j];
                    sum += d2[bottom_r + 1][j + 1] - d2[i][right_c + 2];
                    sum += d1[bottom_r + 1][j + 1] - d1[i][left_c];
                    sum += d2[i + 1][left_c + 1] - d2[top_r][j + 2];

                    sum -= grid[top_r][j];
                    sum -= grid[i][right_c];
                    sum -= grid[bottom_r][j];
                    sum -= grid[i][left_c];

                    s.insert(sum);
                }
            }
        }

        vector<int> ans;
        for (auto it = s.rbegin(); it != s.rend() && ans.size() < 3; it++) {
            ans.push_back(*it);
        }

        return ans;
    }
};
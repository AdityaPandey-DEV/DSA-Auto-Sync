class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Prefix sum for X and Y
        vector<vector<int>> px(n, vector<int>(m, 0));
        vector<vector<int>> py(n, vector<int>(m, 0));

        // Build prefix sum
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                px[i][j] = (grid[i][j] == 'X');
                py[i][j] = (grid[i][j] == 'Y');

                if(i > 0) {
                    px[i][j] += px[i-1][j];
                    py[i][j] += py[i-1][j];
                }
                if(j > 0) {
                    px[i][j] += px[i][j-1];
                    py[i][j] += py[i][j-1];
                }
                if(i > 0 && j > 0) {
                    px[i][j] -= px[i-1][j-1];
                    py[i][j] -= py[i-1][j-1];
                }
            }
        }

        int ans = 0;

        // Check all submatrices from (0,0) to (i,j)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(px[i][j] == py[i][j] && px[i][j] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
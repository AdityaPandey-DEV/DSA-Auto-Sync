class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, '#');

        char ch = 'a';

        // Step 1: Assign characters
        for (int i = 0; i < n; i++) {
            if (s[i] == '#') {
                if (ch > 'z') return "";
                s[i] = ch;

                for (int j = i + 1; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        s[j] = ch;
                    }
                }
                ch++;
            }
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == s[j]) {
                    if (i + 1 < n && j + 1 < n)
                        dp[i][j] = dp[i + 1][j + 1] + 1;
                    else
                        dp[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] != lcp[i][j]) {
                    return "";
                }
            }
        }

        return s;
    }
};
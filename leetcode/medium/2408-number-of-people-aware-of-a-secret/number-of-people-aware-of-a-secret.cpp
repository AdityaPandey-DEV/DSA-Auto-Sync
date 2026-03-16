class Solution {
 public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<long long> ans(n, 0);
    const int MOD = 1e9 + 7;
    long long an = 0;
    ans[0] = 1;
    int j = 0;
    while (j < n) {
      if (ans[j] > 0) {
        for (int i = j + delay; i < min(n, j + forget); i++) {
          ans[i] = (ans[i] + ans[j]) % MOD;
        }
      }
      j++;
    }
    for (int i = n - forget; i < n; i++) {
      an = (an + ans[i]) % MOD;
    }
    return an;
  }
};
class Solution {
 public:
  const int MOD = 1000000007;

  int numberOfStableArrays(int zero, int one, int limit) {
    vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1, 0));
    vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1, 0));

    for (int z = 1; z <= min(zero, limit); z++) dp0[z][0] = 1;

    for (int o = 1; o <= min(one, limit); o++) dp1[0][o] = 1;

    for (int z = 0; z <= zero; z++) {
      for (int o = 0; o <= one; o++) {
        for (int k = 1; k <= limit && k <= z; k++) {
          dp0[z][o] = (dp0[z][o] + dp1[z - k][o]) % MOD;
        }

        for (int k = 1; k <= limit && k <= o; k++) {
          dp1[z][o] = (dp1[z][o] + dp0[z][o - k]) % MOD;
        }
      }
    }

    return (dp0[zero][one] + dp1[zero][one]) % MOD;
  }
};
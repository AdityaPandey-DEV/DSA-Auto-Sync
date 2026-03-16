class Solution {
 public:
  int numSub(string s) {
    long long cnt = 0;
    long long ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        cnt++;
        ans += cnt;
      } else {
        cnt = 0;
      }
    }
    return ans % 1000000007;
  }
};
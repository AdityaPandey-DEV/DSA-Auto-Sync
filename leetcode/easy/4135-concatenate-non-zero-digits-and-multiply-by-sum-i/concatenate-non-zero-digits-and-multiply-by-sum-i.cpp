class Solution {
 public:
  long long sumAndMultiply(int n) {
    long long X = 0;
    int sum = 0;
    string ss = "";
    string s = to_string(n);
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != '0') {
        ss += s[i];
        sum += s[i] - '0';
      }
    }
    if (ss.empty()) return 0;
    X = stoi(ss);
    return X * sum;
  }
};
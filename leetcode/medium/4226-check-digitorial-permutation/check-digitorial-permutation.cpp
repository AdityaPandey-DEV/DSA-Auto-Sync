class Solution {
  int factorials(int n) {
    int ans = 1;
    if (n == 0) return 1;
    for (int i = 1; i <= n; i++) {
      ans *= i;
    }
    return ans;
  }

 public:
  bool isDigitorialPermutation(int n) {
    string no = to_string(n);
    string pelorunaxi = no;
    sort(no.begin(), no.end());

    do {
      if (no[0] == '0') continue;
      int sum = 0;
      for (auto i : no) {
        int a = i - '0';
        sum += factorials(a);
      }
      if (sum == stoi(no)) {
        return true;
      }
    } while (next_permutation(no.begin(), no.end()));

    return false;
  }
};
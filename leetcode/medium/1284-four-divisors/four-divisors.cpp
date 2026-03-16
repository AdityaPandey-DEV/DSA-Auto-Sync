class Solution {
 public:
  int sumFourDivisors(vector<int>& nums) {
    int ans = 0;
    for (int n : nums) {
      int sum = 0;
      int sumn = 0;
      for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
          sumn += i;
          sum++;
          if (i != n / i) {
            sumn += n / i;
            sum++;
          }
        }
      }

      if (sum == 4) {
        ans += sumn;
      }
      sum = 0;
      sumn = 0;
    }

    return ans;
  }
};
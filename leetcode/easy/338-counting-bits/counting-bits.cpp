class Solution {
  int count(int n) {
    int count = 0;  // initialize

    while (n) {
      n = n & (n - 1);  // remove rightmost set bit
      count++;
    }

    return count;  // return result
  }

 public:
  vector<int> countBits(int n) {
    vector<int> ans;
    for (int i = 0; i <= n; i++) {
      ans.push_back(count(i));
    }
    return ans;
  }
};
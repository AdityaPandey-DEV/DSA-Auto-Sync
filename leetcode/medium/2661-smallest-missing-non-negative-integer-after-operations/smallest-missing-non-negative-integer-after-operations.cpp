class Solution {
 public:
  int findSmallestInteger(vector<int>& nums, int value) {
    vector<int> hash(value, 0);

    for (int i = 0; i < nums.size(); i++) {
      int mod = ((nums[i] % value) + value) % value;
      hash[mod]++;
    }

    int ans = 0;
    while (true) {
      int mod = ans % value;
      if (hash[mod] == 0) return ans;
      hash[mod]--;
      ans++;
    }
  }
};
class Solution {
 public:
  int repeatedNTimes(vector<int>& nums) {
    int n = nums.size() / 2 - 1;
    sort(nums.begin(), nums.end());
    int cnt = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == nums[i + 1]) {
        cnt++;
      }
      if (cnt == n) {
        return nums[i];
      }
    }
    return 0;
  }
};
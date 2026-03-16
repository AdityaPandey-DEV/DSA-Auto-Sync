class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    int left = 0;
    int minLen = n + 1;

    for (int right = 0; right < n; right++) {
      sum += nums[right];
      while (sum >= target) {
        minLen = min(minLen, right - left + 1);
        sum -= nums[left];
        left++;
      }
    }
    if (minLen == n + 1) {
      return 0;
    } else {
      return minLen;
    }
  }
};
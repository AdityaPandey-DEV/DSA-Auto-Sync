class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> answer(nums.size(), 1);
    int prefix = 1;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      answer[i] = prefix;
      prefix *= nums[i];
    }
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
      answer[i] *= suffix;
      suffix *= nums[i];
    }
    return answer;
  }
};
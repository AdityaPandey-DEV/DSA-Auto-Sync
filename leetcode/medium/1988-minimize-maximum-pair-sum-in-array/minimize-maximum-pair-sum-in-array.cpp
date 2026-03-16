class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    int maxNo = INT_MIN;
    for (int i = 0; i < size / 2; i++) {
      maxNo = max(nums[i] + nums[size - i - 1], maxNo);
    }
    return maxNo;
  }
};
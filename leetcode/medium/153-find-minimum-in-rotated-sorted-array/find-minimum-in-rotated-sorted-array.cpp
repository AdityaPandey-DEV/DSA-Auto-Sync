class Solution {
 public:
  int findMin(vector<int>& nums) {
    int left = 0;
    int n = nums.size();
    int right = n - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      int pre = (mid + n - 1) % n;
      int next = (mid + 1) % n;
      if (nums[mid] <= nums[pre] && nums[mid] <= nums[next]) {
        return nums[mid];
      } else if (nums[right] > nums[mid]) {
        right = mid - 1;

      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
};
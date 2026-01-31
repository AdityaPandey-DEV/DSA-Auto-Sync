class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int pe = -1;
    for (int n : nums) {
      if (pe == n) {
        return true;
      }
      pe = n;
    }
    return false;
  }
};
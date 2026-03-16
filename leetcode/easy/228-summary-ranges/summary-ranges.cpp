class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    for (int i = 0; i < nums.size(); i++) {
      int left = nums[i];
      string s = to_string(nums[i]);
      while (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1]) {
        i++;
      }
      if (left != nums[i]) {
        s = s + "->";
        s = s + to_string(nums[i]);
      }
      ans.push_back(s);
    }
    return ans;
  }
};
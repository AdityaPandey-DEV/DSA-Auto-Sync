class Solution {
 public:
  string findDifferentBinaryString(vector<string>& nums) {
    string ans = nums[0];
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i][i] == '0')
        ans[i] = '1';
      else
        ans[i] = '0';
    }
    return ans;
  }
};
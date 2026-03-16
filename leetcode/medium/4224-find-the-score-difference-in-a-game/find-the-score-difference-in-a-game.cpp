class Solution {
 public:
  int scoreDifference(vector<int>& nums) {
    bool firstPlayer = true;
    bool secondPlayer = false;

    int firstPlayerScore = 0;
    int secondPlayerScore = 0;

    int n = nums.size();

    for (int i = 0; i < n; i++) {
      if (nums[i] % 2 != 0) {
        swap(firstPlayer, secondPlayer);
      }
      if ((i + 1) % 6 == 0) {
        swap(firstPlayer, secondPlayer);
      }

      if (firstPlayer) {
        firstPlayerScore += nums[i];
      }
      if (secondPlayer) {
        secondPlayerScore += nums[i];
      }
    }
    return firstPlayerScore - secondPlayerScore;
  }
};
class Solution {
  bool Check(vector<int> freq) {
    int common = 0;
    for (int i = 0; i < 26; i++) {
      if (freq[i] == 0) continue;
      if (common == 0)
        common = freq[i];
      else if (freq[i] != common) {
        return false;
      }
    }
    return true;
  }

 public:
  int longestBalanced(string s) {
    int maxL = 0;
    for (int i = 0; i < s.length(); i++) {
      vector<int> freq(26, 0);
      for (int j = i; j < s.length(); j++) {
        freq[s[j] - 'a']++;
        if (Check(freq)) {
          maxL = max(maxL, j - i + 1);
        }
      }
    }
    return maxL;
  }
};
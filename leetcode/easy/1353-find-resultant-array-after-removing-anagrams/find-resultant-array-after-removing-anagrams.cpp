class Solution {
  bool Anagram(vector<string> words, int cur, int pre) {
    sort(words[cur].begin(), words[cur].end());
    sort(words[pre].begin(), words[pre].end());
    if (words[cur] == words[pre]) {
      return true;
    } else {
      return false;
    }
  }

 public:
  vector<string> removeAnagrams(vector<string>& words) {
    int pre = 0, cur = 1;
    vector<string> ans;
    while (cur < words.size()) {
      if (Anagram(words, cur, pre)) {
        words[cur] = "";
        cur++;

      } else {
        cur++;
        pre = cur - 1;
      }
    }
    for (int i = 0; i < words.size(); i++) {
      if (words[i] != "") {
        ans.push_back(words[i]);
      }
    }
    return ans;
  }
};
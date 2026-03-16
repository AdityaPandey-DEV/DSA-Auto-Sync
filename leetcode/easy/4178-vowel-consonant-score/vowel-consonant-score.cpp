class Solution {
 public:
  int vowelConsonantScore(string s) {
    int v = 0;
    int c = 0;
    string vowel = "aeiou";
    for (int i = 0; i < s.size(); i++) {
      if (!isalpha(s[i])) continue;
      bool isVowel = false;
      for (char c : vowel) {
        if (c == s[i]) {
          isVowel = true;
        }
      }
      if (isVowel) {
        v++;
      } else {
        c++;
      }
    }
    int score = 0;
    if (c > 0) {
      score = v / c;
    }

    return score;
  }
};
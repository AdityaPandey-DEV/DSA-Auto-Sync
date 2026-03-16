class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    stringstream ss(s);
    vector<string> sa;
    string word;
    while (ss >> word) {
      sa.push_back(word);
    }

    if (sa.size() != pattern.size()) return false;

    map<char, string> cs;
    map<string, char> sc;

    for (int i = 0; i < pattern.size(); i++) {
      char c = pattern[i];
      string w = sa[i];

      if (cs.find(c) != cs.end()) {
        if (cs[c] != w) return false;
      } else {
        cs[c] = w;
      }

      if (sc.find(w) != sc.end()) {
        if (sc[w] != c) return false;
      } else {
        sc[w] = c;
      }
    }

    return true;
  }
};
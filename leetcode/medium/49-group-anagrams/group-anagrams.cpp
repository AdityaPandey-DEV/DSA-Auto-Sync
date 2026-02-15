class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> mp;
    for (auto s : strs) {
      string st = s;
      sort(s.begin(), s.end());
      mp[s].push_back(st);
    }
    vector<vector<string>> res;
    for (auto m : mp) {
      res.push_back(m.second);
    }
    return res;
  }
};
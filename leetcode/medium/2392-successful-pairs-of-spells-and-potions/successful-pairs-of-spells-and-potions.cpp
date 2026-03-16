class Solution {
 public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                              long long success) {
    vector<int> ans;
    int a = 0;
    int n = spells.size();
    int m = potions.size();
    sort(potions.begin(), potions.end());

    for (int i = 0; i < n; i++) {
      long long k = (success + spells[i] - 1) / spells[i];
      auto it = lower_bound(potions.begin(), potions.end(), k);
      int index = it - potions.begin();
      a = m - index;

      ans.push_back(a);
      a = 0;
    }
    return ans;
  }
};
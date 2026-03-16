#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool isNo(int num) {
    string s = to_string(num);
    vector<int> freq(10, 0);
    for (char ch : s) freq[ch - '0']++;
    for (int d = 0; d <= 9; d++) {
      if (freq[d] > 0 && freq[d] != d) return false;
    }
    return true;
  }

 public:
  int nextBeautifulNumber(int n) {
    for (int i = n + 1; i <= 10000000; i++) {
      if (isNo(i)) return i;
    }
    return -1;
  }
};

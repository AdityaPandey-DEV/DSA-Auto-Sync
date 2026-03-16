class Solution {
 public:
  bool isPalindrome(string s) {
    string z;
    for (int i = 0; i < s.length(); i++) {
      if (isalnum(s[i])) {
        if (isupper(s[i])) {
          z.push_back(tolower(s[i]));

        } else {
          z.push_back(s[i]);
        }
      }
    }

    int i = 0;
    int j = z.length() - 1;
    bool is = true;
    while (i < j) {
      if (z[i] != z[j]) is = false;
      i++;
      j--;
    }

    return is;
  }
};
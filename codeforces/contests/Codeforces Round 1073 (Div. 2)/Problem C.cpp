#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int pos1 = -1, pos0 = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        pos1 = i;
        break;
      }
    }
    if (pos1 != -1) {
      for (int i = pos1 + 1; i < n; i++) {
        if (s[i] == '0') {
          pos0 = i;
          break;
        }
      }
    }
    if (pos1 == -1 || pos0 == -1) {
      cout << "Bob\n";
    } else {
      cout << "Alice\n";
      cout << 2 << "\n";
      cout << pos1 + 1 << " " << pos0 + 1 << "\n";
    }
  }
  return 0;
}
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> vc;
    while (n--) {
      int i;
      cin >> i;
      vc.push_back(i);
    }
    bool found = false;
    for (int i = 0; i < vc.size(); i++) {
      int product = 1;
      for (int j = i; j < vc.size(); j++) {
        product = product * vc[j];
        if (product == 67) {
          found = true;
          break;
        }
      }
      if (found)
        break;
    }
    if (found) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    cout << endl;
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    bool changed = true;
    while (changed) {
      changed = false;
      for (int i = 1; 2 * i <= n; i++) {
        if (a[i] > a[2 * i]) {
          swap(a[i], a[2 * i]);
          changed = true;
        }
      }
    }
    // Check if sorted
    bool sorted = true;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[i + 1]) {
        sorted = false;
        break;
      }
    }
    cout << (sorted ? "YES" : "NO") << "\n";
  }
  return 0;
}
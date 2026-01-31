#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<int> vc;
  while (t--) {
    int n;
    cin >> n;
    int maxE = 0;
    for (int i = 0; i < n; i++) {
      int e;
      cin >> e;
      maxE = max(e, maxE);
    }
    cout << maxE * n << endl;
  }
  return 0;
}

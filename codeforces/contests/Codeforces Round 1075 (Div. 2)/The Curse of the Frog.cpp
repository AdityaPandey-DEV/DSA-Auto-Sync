#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  long long x;
  if (!(cin >> n >> x))
    return;
  long long current_dist = 0;
  long long max_gain = -2e18;
  for (int i = 0; i < n; ++i) {
    long long a, b, c;
    cin >> a >> b >> c;
    current_dist += (b - 1) * a;
    long long gain = b * a - c;
    max_gain = max(max_gain, gain);
  }
  if (current_dist >= x) {
    cout << 0 << "\n";
    return;
  }
  if (max_gain <= 0) {
    cout << -1 << "\n";
    return;
  }
  long long needed = x - current_dist;
  long long rollbacks = (needed + max_gain - 1) / max_gain;
  cout << rollbacks << "\n";
}

int main() {
  int t;
  if (cin >> t) {
    while (t--) {
      solve();
    }
  }
  return 0;
}

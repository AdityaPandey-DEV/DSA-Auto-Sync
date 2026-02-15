#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> f(n + 1);
    for (int i = 1; i <= n; i++) cin >> f[i];
    vector<long long> a(n + 1);
    vector<long long> d(n + 1);
    for (int x = 1; x < n; x++) d[x] = f[x + 1] - f[x];
    for (int x = 1; x <= n - 2; x++) {
      a[x + 1] = (d[x + 1] - d[x]) / 2;
    }
    long long known = 0;
    for (int i = 2; i <= n - 1; i++) known += (long long)(i - 1) * a[i];
    a[n] = (f[1] - known) / (n - 1);
    long long mid = 0;
    for (int i = 2; i <= n - 1; i++) mid += a[i];
    a[1] = d[1] + mid + a[n];
    for (int i = 1; i <= n; i++) {
      cout << a[i];
      if (i < n) cout << " ";
    }
    cout << "\n";
  }
  return 0;
}

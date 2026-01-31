#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve() {
  int n;
  long long h, l;
  if (!(cin >> n >> h >> l))
    return;

  vector<int> a(n);
  int n_R = 0; // Row-only: val <= h AND val > l
  int n_C = 0; // Col-only: val > h AND val <= l
  int n_F = 0; // Flexible: val <= h AND val <= l

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    bool is_row = (a[i] <= h);
    bool is_col = (a[i] <= l);

    if (is_row && is_col) {
      n_F++;
    } else if (is_row) {
      n_R++;
    } else if (is_col) {
      n_C++;
    }
  }

  // Greedy matching
  // 1. Match R with C
  int pairs = min(n_R, n_C);
  n_R -= pairs;
  n_C -= pairs;

  // Now at least one of n_R or n_C is 0.

  // 2. Match remaining R with F
  if (n_R > 0) {
    int take = min(n_R, n_F);
    pairs += take;
    n_F -= take;
    n_R -= take;
  }

  // 3. Match remaining C with F
  if (n_C > 0) {
    int take = min(n_C, n_F);
    pairs += take;
    n_F -= take;
    n_C -= take;
  }

  // 4. Match remaining F with F
  pairs += n_F / 2;

  cout << pairs << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  if (cin >> t) {
    while (t--) {
      solve();
    }
  }
  return 0;
}

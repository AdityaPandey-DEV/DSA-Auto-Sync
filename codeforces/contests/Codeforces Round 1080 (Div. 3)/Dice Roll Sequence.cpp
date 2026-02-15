#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<vector<int>> memo;

bool isAdj(int x, int y) { return x != y && x + y != 7; }

int solve(int i, int prev) {
  if (i == n)
    return 0;
  if (memo[i][prev] != -1)
    return memo[i][prev];
  int res = 1e9;
  for (int j = 1; j <= 6; j++) {
    if (prev == 0 || isAdj(prev, j)) {
      int cost = (a[i] == j) ? 0 : 1;
      res = min(res, cost + solve(i + 1, j));
    }
  }
  return memo[i][prev] = res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    memo.assign(n, {-1, -1, -1, -1, -1, -1, -1});
    cout << solve(0, 0) << "\n";
  }
  return 0;
}

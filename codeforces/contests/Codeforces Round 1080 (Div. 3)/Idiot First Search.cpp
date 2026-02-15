#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> L[i] >> R[i];
    vector<int> order;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      order.push_back(v);
      if (L[v] != 0) {
        q.push(L[v]);
        q.push(R[v]);
      }
    }
    vector<long long> step_up(n + 1);
    for (int i = order.size() - 1; i >= 0; i--) {
      int v = order[i];
      if (L[v] == 0)
        step_up[v] = 1;
      else
        step_up[v] = (step_up[L[v]] + step_up[R[v]] + 3) % MOD;
    }
    vector<long long> ans(n + 1);
    ans[1] = step_up[1];
    for (int v : order) {
      if (L[v] != 0) {
        ans[L[v]] = (step_up[L[v]] + ans[v]) % MOD;
        ans[R[v]] = (step_up[R[v]] + ans[v]) % MOD;
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i];
      if (i < n)
        cout << " ";
    }
    cout << "\n";
  }
  return 0;
}

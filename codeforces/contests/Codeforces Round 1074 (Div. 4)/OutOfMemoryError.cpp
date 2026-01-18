#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        long long h;
        cin >> n >> m >> h;
        vector<long long> original(n), cur(n);
        for (int i = 0; i < n; i++) {
            cin >> original[i];
            cur[i] = original[i];
        }
        while (m--) {
            int b;
            long long c;
            cin >> b >> c;
            b--;
            cur[b] += c;
            if (cur[b] > h) {
                cur = original;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << cur[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
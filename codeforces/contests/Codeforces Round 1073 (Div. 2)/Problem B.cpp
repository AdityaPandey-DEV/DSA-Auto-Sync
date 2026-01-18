#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        unordered_map<int,int> freq;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        int mex = 0;
        while (freq[mex] > 0) {
            mex++;
        }

        if (mex == 0) {
            cout << "NO\n";
        } else if (mex == 1) {
            cout << (freq[0] == 1 ? "YES\n" : "NO\n");
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
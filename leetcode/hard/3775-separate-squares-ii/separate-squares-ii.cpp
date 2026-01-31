#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  struct Event {
    long long y;
    int type;  // +1 add, -1 remove
    int l, r;  // compressed x indices
  };

  struct SegTree {
    int n;
    vector<int> cover;
    vector<long long> length;
    vector<long long> xs;

    SegTree(int n, vector<long long>& xs) : n(n), xs(xs) {
      cover.assign(4 * n, 0);
      length.assign(4 * n, 0);
    }

    void pushUp(int node, int l, int r) {
      if (cover[node] > 0) {
        length[node] = xs[r + 1] - xs[l];
      } else if (l == r) {
        length[node] = 0;
      } else {
        length[node] = length[node * 2] + length[node * 2 + 1];
      }
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
      if (ql > r || qr < l) return;
      if (ql <= l && r <= qr) {
        cover[node] += val;
        pushUp(node, l, r);
        return;
      }
      int mid = (l + r) / 2;
      update(node * 2, l, mid, ql, qr, val);
      update(node * 2 + 1, mid + 1, r, ql, qr, val);
      pushUp(node, l, r);
    }

    long long query() { return length[1]; }
  };

  double separateSquares(vector<vector<int>>& squares) {
    vector<long long> xs;
    vector<Event> events;

    for (auto& s : squares) {
      long long x = s[0], y = s[1], l = s[2];
      xs.push_back(x);
      xs.push_back(x + l);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    auto getX = [&](long long x) {
      return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    };

    for (auto& s : squares) {
      long long x = s[0], y = s[1], l = s[2];
      int L = getX(x);
      int R = getX(x + l) - 1;
      events.push_back({y, +1, L, R});
      events.push_back({y + l, -1, L, R});
    }

    sort(events.begin(), events.end(),
         [](auto& a, auto& b) { return a.y < b.y; });

    SegTree st(xs.size() - 1, xs);

    long long prevY = events[0].y;
    long double totalArea = 0;

    for (int i = 0; i < events.size();) {
      long long currY = events[i].y;
      long long width = st.query();
      totalArea += width * (currY - prevY);

      while (i < events.size() && events[i].y == currY) {
        st.update(1, 0, st.n - 1, events[i].l, events[i].r, events[i].type);
        i++;
      }
      prevY = currY;
    }

    long double target = totalArea / 2.0;
    long double currArea = 0;
    st = SegTree(xs.size() - 1, xs);
    prevY = events[0].y;

    for (int i = 0; i < events.size();) {
      long long currY = events[i].y;
      long long width = st.query();
      long double slabArea = width * (currY - prevY);

      if (currArea + slabArea >= target) {
        return (double)(prevY + (target - currArea) / width);
      }

      currArea += slabArea;

      while (i < events.size() && events[i].y == currY) {
        st.update(1, 0, st.n - 1, events[i].l, events[i].r, events[i].type);
        i++;
      }
      prevY = currY;
    }

    return (double)prevY;
  }
};
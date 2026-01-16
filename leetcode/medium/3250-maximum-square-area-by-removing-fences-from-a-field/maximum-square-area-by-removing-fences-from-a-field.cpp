class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
       
        vector<int> h(hFences.begin(), hFences.end());
        vector<int> v(vFences.begin(), vFences.end());
        h.insert(h.begin(), 1);
        v.insert(v.begin(), 1);
        h.push_back(m);
        v.push_back(n);
        unordered_set<int> s;
        for (int i = 0; i < h.size(); i++) {
            for (int j = i+1; j < h.size(); j++) {
                s.insert(abs(h[i] - h[j]));
            }
        }
        int maxSide = 0;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i+1; j < v.size(); j++) {
                if (s.contains(abs(v[i] - v[j])))
                    maxSide = max(abs(v[i] - v[j]), maxSide);
            }
        }
        if (maxSide == 0) {
            return -1;
        } else
            return (1LL*maxSide*maxSide)%1000000007;
    }
};
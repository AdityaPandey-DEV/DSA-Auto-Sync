class Solution {
 public:
  typedef pair<int, vector<int>> pv;
  priority_queue<pv> heap;
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> ans;
    for (auto v : points) {
      heap.push({pow(v[0], 2) + pow(v[1], 2), {v[0], v[1]}});
      if (heap.size() > k) {
        heap.pop();
      }
    }
    while (!heap.empty()) {
      ans.push_back(heap.top().second);
      heap.pop();
    }
    return ans;
  }
};
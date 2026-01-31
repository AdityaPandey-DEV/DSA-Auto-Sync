class Solution {
 public:
  long long largestSquareArea(vector<vector<int>>& bottomLeft,
                              vector<vector<int>>& topRight) {
    long long maxArea = 0;
    int size = bottomLeft.size();
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        int left = max(bottomLeft[i][0], bottomLeft[j][0]);
        int right = min(topRight[i][0], topRight[j][0]);
        int bottom = max(bottomLeft[i][1], bottomLeft[j][1]);
        int top = min(topRight[i][1], topRight[j][1]);

        if (right > left && top > bottom) {
          int height = top - bottom;
          int width = right - left;
          int side = min(height, width);
          long long area = 1ll * side * side;
          maxArea = max(maxArea, area);
        }
      }
    }
    return maxArea;
  }
};
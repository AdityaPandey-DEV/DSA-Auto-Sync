class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;
        int size=nums.size();
        sort(nums.begin(),nums.end());
        
        int ans = INT_MAX;

        for (int i = k; i<= size; i++) {
            ans = min(ans, nums[i-1] - nums[i-k]);
        }

        return ans;
    }
};
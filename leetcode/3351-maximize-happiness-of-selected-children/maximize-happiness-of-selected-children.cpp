class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());   
        
        long long ans = 0;
        int n = happiness.size();
        
        for (int i = 0; i < k; i++) {               
            int val = happiness[n - 1 - i] - i;     
            if (val <= 0) break;                     
            ans += val;
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            for(int j=0;j<nums.size();j++){
                if(j==i){
                    continue;
                }
                if(nums[i]>nums[j]){
                    cnt++;
                }
            }
            ans[i]=cnt;
        }
        return ans;
        
    }
};
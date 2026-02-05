class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int size=nums.size();
        vector<int>ans(size,-1);
        for(int i=0;i<size;i++){
            if(nums[i]>=0){
                ans[i]=nums[(nums[i]+i)%size];
            }
            else{
                int ind=(i+size+(nums[i]%size))%size;
                ans[i]=nums[ind];
            }
            
        }
        return ans;

        
    }
};
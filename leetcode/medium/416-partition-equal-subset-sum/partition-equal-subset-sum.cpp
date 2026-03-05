class Solution {
    bool subsetSum(vector<int>& arr,int i,int target,vector<vector<int>>&dp){
        if(target==0){
            return true;
        }
        if(i==arr.size()||target<0){
            return false;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool take=subsetSum(arr,i+1,target-arr[i],dp);
        bool notTake=subsetSum(arr,i+1,target,dp);
        return dp[i][target]=take||notTake;
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>>dp(nums.size()+1,vector<int>((sum/2)+1,-1));
        return subsetSum(nums,0,sum/2,dp);
    }
};
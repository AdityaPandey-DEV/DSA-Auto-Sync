class Solution {
public:
    void rec(vector<int>& nums ,vector<vector<int>>&ans,int i,vector<int>a){
        if(i<0){
            ans.push_back(a);
            return;
        }
        
        rec(nums,ans,i-1,a);
        a.push_back(nums[i]);
        
        rec(nums,ans,i-1,a);
        a.pop_back();


    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>a;
        int i=nums.size();
        rec(nums,ans,i-1,a);
        return ans;


        
    }
};
class Solution {
    void rec(vector<int>& candidates ,vector<vector<int>>&ans,int i,vector<int>&a, int target){
        if(target==0){
            ans.push_back(a);
            return;
        }
        if(i==candidates.size()||target<0){
            return;
        }
        
        rec(candidates,ans,i+1,a,target);
        a.push_back(candidates[i]);
        
        rec(candidates,ans,i,a,target-candidates[i]);
        a.pop_back();


    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>a;
        int i=candidates.size();
        rec(candidates,ans,0,a,target);
        
        return ans;
        
        
    }
};
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min=*min_element(nums.begin(),nums.end());
        int max=*max_element(nums.begin(),nums.end());
        vector<int>ans;
        vector<int>h(max-min+1,0);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            h[nums[i]-min]++;
        }
        for(int i=0;i<h.size();i++){
            if(h[i]==0){
                ans.push_back(i+min);
            }
        }

        return ans;
        
        
    }
};
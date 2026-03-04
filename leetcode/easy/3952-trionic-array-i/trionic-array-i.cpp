class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int s=nums.size();
        if(s<3) return false;
        int i=0;
        while (i + 1 < s && nums[i] < nums[i + 1]){
            i++;
        }
        if (i == 0) return false; 
        while (i + 1 < s && nums[i] > nums[i + 1]){
            i++;
        }
        if (i == s - 1) return false;

        while (i + 1 < s && nums[i] < nums[i + 1]){
            i++;
        }
        return i == s - 1;

        

    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size=nums.size();
        int seq=0;
        int lSeq=0;
        if(size==0) return 0;
        for(int i=0;i<size-1;i++){
            if(nums[i+1]-1==nums[i]){
                seq++;
            }
            else if(nums[i+1]==nums[i]){
                continue;
            }
            else{
                seq=0;
            }
            lSeq=max(seq,lSeq);

        }
        return lSeq+1;
        
    }
};

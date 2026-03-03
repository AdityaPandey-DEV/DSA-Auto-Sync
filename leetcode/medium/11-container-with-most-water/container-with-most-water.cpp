class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0;
        int right=height.size()-1;
        long long maxVol=0;
        while(left<right){
            long long vol =min(height[left],height[right])*(right-left);
            maxVol=max(vol,maxVol);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }


        }
        return maxVol;
        
    }
};
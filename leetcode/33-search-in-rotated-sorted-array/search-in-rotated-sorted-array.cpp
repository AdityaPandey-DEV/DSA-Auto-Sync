class Solution {
    int binarySearch(vector<int>& nums,int left,int right, int target) {
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return -1;
        
    }
    int findMin(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        int right=n-1;
    
        while(left<=right){
            int mid=left+(right-left)/2;
            int pre=(mid+n-1)%n;
            int next=(mid+1)%n;
            if(nums[mid]<=nums[pre]&&nums[mid]<=nums[next]){
                return mid;
            }
            else if(nums[right]>nums[mid]){
                right=mid-1;

            }
            else{
                left=mid+1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int min=findMin(nums);
        return max(binarySearch(nums,0,min-1,target),binarySearch(nums,min,nums.size()-1,target));
        
    }
};
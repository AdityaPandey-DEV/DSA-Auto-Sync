class Solution {
public:
priority_queue<int,vector<int>,greater<int>>heap;
    int findKthLargest(vector<int>& nums, int k) {
        for(int i:nums){
            heap.push(i);
            if(heap.size()>k){
                heap.pop();
            }
        }
        return heap.top();
        
    }
};
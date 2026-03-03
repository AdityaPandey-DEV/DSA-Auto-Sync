class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nm = n + m;
        vector<int> nums12(nm);
        int i = 0; 
        int j = 0; 
        int k = 0; 

        
        while (j < m && k < n) {
            if (nums1[j] < nums2[k]) {
                nums12[i++] = nums1[j++];
            } else {
                nums12[i++] = nums2[k++];
            }
        }

        while (j < m) {
            nums12[i++] = nums1[j++];
        }

        
        while (k < n) {
            nums12[i++] = nums2[k++];
        }

        nums1 = nums12;
    }
};
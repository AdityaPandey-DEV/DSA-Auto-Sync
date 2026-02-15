class Solution {
public:
    int reverseBits(int n) {
        int ans;
        int count=32;
        while(count--){
            ans <<= 1;        
            ans |= (n & 1);   
            n >>= 1; 
        }
        return ans;
        
    }
};
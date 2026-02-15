class Solution {
public:
    int hammingWeight(int n) {
        int count;
        while(n){
            n=n&(n-1);
            count++;
        }
        return count;
        
    }
};
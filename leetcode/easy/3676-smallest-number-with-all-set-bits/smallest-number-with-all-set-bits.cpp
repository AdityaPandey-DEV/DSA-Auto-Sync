class Solution {
public:
    int smallestNumber(int n) {
        int i=1;
        while(i<n){
            i=i<<1|1;
        }
        n=i;
        return n;
    }
};
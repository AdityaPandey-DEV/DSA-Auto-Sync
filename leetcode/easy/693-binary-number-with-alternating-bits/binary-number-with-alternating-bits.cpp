class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool pre=false;
        if(n&1){
            pre=true;
        }
        n=n>>1;
        bool curr=false;
        while(n){
            
            if(n&1){
                curr=true;
            }
            else{
                curr=false;
            }
            n=n>>1;
            if(curr==pre){
                return false;
            }
            pre=curr;
            
        }   
        return true;     
    }
};
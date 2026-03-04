class Solution {

public:
    int numberOfWays(string corridor) {
        const int mod=1e9+7;
        int ans=1;
        int s=0;
        int size=0;
        for(int i=0;i<corridor.size();i++){
            
            if(corridor[i]=='S'){

                s++;
            }
            if(s==2){
                size++;

            }
            if(s==3){
                ans=(ans*1ll*size)%mod;
                size=0;
                s=1;
            }
        }
        if(s!=2){
            return 0;
        }
        return ans;
        
    }
};
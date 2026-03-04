class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int j=1;
        int i=1;
        int k=1;
        while(i<=n){
            if(j%(k+7)==0){
                k++;
                j=k;
                  
            }
            ans+=j;
            i++;
            j++;
            
        }  
    return ans;       
    }
};
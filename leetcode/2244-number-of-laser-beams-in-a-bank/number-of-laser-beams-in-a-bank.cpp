class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int a=0;
        int ans=0;
        int pre=0;
        
        
        for(int i=0;i<n;i++){
            string s=bank[i];
            int m=s.length();
            int curr=0;
            
            
        

            for(int j=0;j<m;j++){
                if(s[j]=='1'){
                    curr++;
                }
                
            }
            if(curr!=0){
            ans=ans+(pre*curr);
            pre=curr;
                    
            }

            
        
        }
    return ans;
        
    }
};
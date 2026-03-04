class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int sum=0;
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                sum++;
            }
        }
        int min=sum;
        for(int i=0;i<n;i++){
            
            if(customers[i]=='Y'){
                sum--;
            }
            if(customers[i]=='N'){
                sum++;
            }
            if(sum<min){
                min=sum;
                ans=i+1;
            }
            
        }
        return ans;

        
    }
};
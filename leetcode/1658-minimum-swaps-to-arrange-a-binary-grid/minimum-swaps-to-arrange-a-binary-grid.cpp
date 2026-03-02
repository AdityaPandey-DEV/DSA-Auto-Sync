class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>endOfZero(n,0);
        for(int i=0;i<n;i++){
            int j=n-1;
            int cnt=0;
            while(j>=0 &&grid[i][j]==0){
                cnt++;
                j--;
            }
            endOfZero[i]=cnt;
        }
        int steps=0;
        for(int i=0;i<n;i++){
            int no=n-i-1;
            int j=i;
            
            while(j<n && endOfZero[j] < no){
                j++;
            }
            if(j==n){
                return -1;
            }
            

            steps+=j-i;

            while(j>i){
                swap(endOfZero[j],endOfZero[j-1]);
                j--;
            }

        }
        return steps;
        
    }
};
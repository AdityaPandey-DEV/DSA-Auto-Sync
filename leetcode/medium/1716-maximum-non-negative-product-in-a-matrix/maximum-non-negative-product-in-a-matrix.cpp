class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long>>maxDp(n,vector<long long>(m,1));
        vector<vector<long long>>minDp(n,vector<long long>(m,1));
        maxDp[0][0]=minDp[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            maxDp[i][0]=minDp[i][0]=grid[i][0]*maxDp[i-1][0];
        }
        for(int i=1;i<m;i++){
            maxDp[0][i]=minDp[0][i]=grid[0][i]*maxDp[0][i-1];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                long long val=grid[i][j];
                long long a=maxDp[i-1][j]*val;
                long long b=maxDp[i][j-1]*val;
                long long c=minDp[i-1][j]*val;
                long long d=minDp[i][j-1]*val;
                maxDp[i][j]=max({a,b,c,d});
                minDp[i][j]=min({a,b,c,d});
            }
        }
        long long res=maxDp[n-1][m-1];
        if(res<0) return -1;
        else{
            return res%1000000007;
        }
        
    }
};
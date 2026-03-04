class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat[0].size();
        int m=mat.size();
        vector<int> matx(n,0); 
        vector<int> maty(m,0); 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    maty[i]++;
                    matx[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && matx[j]==1 && maty[i]==1){
                    ans++;
                }
            }
            
        }
        return ans;
    }
};
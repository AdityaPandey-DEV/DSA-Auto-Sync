class Solution {
    void rotate(vector<vector<int>>& mat){
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                swap(mat[i][j],mat[j][i]);
            }
            
        }
        for(int i = 0; i < n; i++){
                reverse(mat[i].begin(), mat[i].end());
            }
    }
    bool check(vector<vector<int>>& mat, vector<vector<int>>& target){
        bool ans=true;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=target[i][j]) ans=false;
            }
        }
        return ans;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool ans=check(mat,target);
        if(ans){
            return ans;
        }
        
        for(int i=0;i<4;i++){
            rotate(mat);
            bool ans=check(mat,target);
            if(ans){
                return ans;
            }
        }
        return false;

        
    }
};
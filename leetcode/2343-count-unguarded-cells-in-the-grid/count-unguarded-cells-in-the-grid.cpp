class Solution {
    void dfs(vector<vector<char>>& grid,int x,int y,int i,int j ){
        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size()){
        if(grid[x][y]=='w'|| grid[x][y] == 'g'){
            return;
        }
        else{
            grid[x][y]='1';
            x+=i;
            y+=j;
            dfs(grid,x,y,i,j);
        }
        }
        else{
            return;
        }

    }
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(n,vector<char>(m,'0'));
        for(auto g :guards){
            grid[g[0]][g[1]]='g';
        }
        for(auto w :walls){
            grid[w[0]][w[1]]='w';
        }
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='g'){
                    for(auto d:dir){
                        int nx=d[0]+i;
                        int ny=d[1]+j;
                        dfs(grid,nx,ny,d[0],d[1]);
                    }
                }

            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0'){
                    ans++;
                    
                }

            }
        }
        return ans;
        



        
    }
};
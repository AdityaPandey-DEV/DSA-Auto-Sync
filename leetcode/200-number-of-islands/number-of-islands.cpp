class Solution {
    void bfs(vector<vector<char>>& grid ,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        queue<pair<int,int>> q;
        visited[i][j]=true;
        q.push({i,j});
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && grid[nr][nc]=='1'){
                    grid[nr][nc]='0';
                    visited[nr][nc]=true;
                    q.push({nr,nc});

                }


            }
        }


    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    bfs(grid,i,j);

                }

            }
        }
        return cnt;
        
    }
};
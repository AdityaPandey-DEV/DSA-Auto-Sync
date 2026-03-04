class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>> visited(n,vector<int>(n,0));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0});
        visited[0][0]=1;
        int ans=0;

        while(!pq.empty()){
            auto top =pq.top();
            pq.pop();
            int height=top[0], x=top[1],y=top[2];
            ans = max(ans,height);

            if(x==n-1 && y==n-1){
                return ans;
            }
            for (auto &d: dir){
                int nx =x+ d[0];
                int ny= y+ d[1];
                if(nx>=0 && ny>=0 && nx<n && ny<n && !visited[nx][ny]){
                    visited[nx][ny]=1;
                    pq.push({grid[nx][ny],nx,ny});
                }
            } 
        }
        return -1;
        
        
    }
};
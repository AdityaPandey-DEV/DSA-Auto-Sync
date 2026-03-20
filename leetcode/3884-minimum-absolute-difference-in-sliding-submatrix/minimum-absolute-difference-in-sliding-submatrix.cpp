class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n-k+1, vector<int>(m-k+1));
        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                
                set<int> s;
                for(int id=i;id<i+k;id++){
                    for(int jd=j;jd<j+k;jd++){
                        s.insert(grid[id][jd]);
                    }
                }
                if(s.size() <= 1){
                    ans[i][j] = 0;
                    continue;
                }
                int mine=INT_MAX;
                auto pre=s.begin();
                auto curr=next(pre);
                while(curr!=s.end()){
                    mine=min(mine,abs(*curr-*pre));
                    pre=curr;
                    curr++;
                }
                ans[i][j]=mine;

            }
        }
        return ans;
    }
};
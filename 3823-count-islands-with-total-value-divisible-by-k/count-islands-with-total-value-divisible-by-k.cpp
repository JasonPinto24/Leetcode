class Solution {
public:
    int m;
    int n;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    void dfs(int i,int j,vector<vector<int>> &grid,long long &sum){
        sum+=grid[i][j];
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int nrow=i+dx[k];
            int ncol=j+dy[k];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol]>0){
                dfs(nrow,ncol,grid,sum);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    long long sum=0;
                    dfs(i,j,grid,sum);
                    if(sum%k==0) ans++;
                }
            }
        }
        return ans;
    }
};
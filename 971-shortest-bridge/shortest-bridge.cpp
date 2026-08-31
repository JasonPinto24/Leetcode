class Solution {
public:
    queue<pair<int,int>>q;
    void dfs(int row,int col,vector<vector<bool>> &visited,vector<vector<int>> &grid){
        visited[row][col]=true;
        vector<int> dx={-1,1,0,0};
        vector<int> dy={0,0,1,-1};
        q.push({row,col});
        for(int i=0;i<4;i++){
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                dfs(nrow,ncol,visited,grid);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int distance=0;
        bool found=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,visited,grid);
                    found=true;
                    break;
                }
            }
            if(found) break;
        }
        vector<int> dx={-1,1,0,0};
        vector<int> dy={0,0,1,-1};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto[row,col]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=row+dx[i];
                    int ncol=col+dy[i];
                    if(nrow<0 || ncol<0 || ncol>=m || nrow>=n) continue;
                    if(grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                        return distance;
                    }
                    if(grid[nrow][ncol]== 0 && !visited[nrow][ncol]){
                        visited[nrow][ncol]=true;
                        q.push({nrow,ncol});
                    }
                }
            }
            distance++;
            
        }
        return -1;
    }
};
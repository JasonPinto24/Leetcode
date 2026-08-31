class Solution {
public:
    vector<pair<int,int>> borders;
    int m;
    int n;
    vector<int> dx={-1,1,0,0};
    vector<int> dy={0,0,1,-1};
    void dfs(vector<vector<int>> &grid,int row,int col,int originalcolor,vector<vector<bool>> &visited){
        visited[row][col]=true;
        bool isborder=false;
        for(int i=0;i<4;i++){
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            if(nrow<0 || ncol<0 || nrow>=m || ncol>=n) isborder=true;
            else if(grid[nrow][ncol]!=originalcolor) isborder=true;
            else if(!visited[nrow][ncol]) dfs(grid,nrow,ncol,originalcolor,visited);

        }
        if(isborder)borders.push_back({row,col});
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int originalcolor=grid[row][col];
        dfs(grid,row,col,originalcolor,visited);
        for(auto &[row,col]:borders){
            grid[row][col]=color;
        }
        return grid;
    }
};
class Solution {
public:
    int m;
    int n;
    bool dfs(int i,int j,vector<vector<int>> &grid1,vector<vector<int>> &grid2){
        if(i<0 || j<0 || i>=m || j>=n) return true;
        if(grid2[i][j]==0) return true;
        grid2[i][j]=0;
        bool current= (grid1[i][j]==1);
        bool up=dfs(i-1,j,grid1,grid2);
        bool down=dfs(i+1,j,grid1,grid2);
        bool left=dfs(i,j-1,grid1,grid2);
        bool right=dfs(i,j+1,grid1,grid2);
        return current && up && down && left && right;

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m=grid1.size();
        n=grid1[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j] && dfs(i,j,grid1,grid2)) count++;
            }
        }
        return count;
    }
};
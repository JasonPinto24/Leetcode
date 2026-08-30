class Solution {
public:
    int dfs(int node,vector<vector<int>> &adj,vector<bool> &visited,vector<bool> &res){
        visited[node]=true;
        int count=1;
        for(int next:adj[node]){
            if(!visited[next] && !res[next]){
                count+=dfs(next,adj,visited,res);
            }
        }
        return count;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> res(n,false);
        for(int x:restricted){
            res[x]=true;
        }
        vector<bool> visited(n,false);
        return dfs(0,adj,visited,res);
    }
};
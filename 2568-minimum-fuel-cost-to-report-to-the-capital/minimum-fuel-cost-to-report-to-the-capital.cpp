class Solution {
public:
    long long fuel;
    int seats;
    int dfs(int node,vector<vector<int>> &adj,vector<bool> &visited){
        visited[node]=true;
        int people=1;
        for(int next:adj[node]){
            if(visited[next]) continue;
            people+=dfs(next,adj,visited);
        }
        if(node!=0){
            fuel+=(people+seats-1)/seats;
        }
        return people;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        this->seats=seats;
        int n=roads.size()+1;
        vector<vector<int>> adj(n);
        for(auto &road:roads){
            int u=road[0];
            int v=road[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<bool> visited(n,false);
        dfs(0,adj,visited);
        return fuel;
    }
};
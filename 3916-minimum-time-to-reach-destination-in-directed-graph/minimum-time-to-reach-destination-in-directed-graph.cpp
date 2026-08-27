class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<array<int,3>>> adj(n);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int start=e[2];
            int end=e[3];
            adj[u].push_back({v,start,end});
        }
        const int INF=1e9;
        vector<int> dist(n,INF);
        dist[0]=0;
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        >pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto[time,u]=pq.top();
            pq.pop();
            if(time>dist[u]) continue;
            if(u==n-1) return dist[u];
            for(auto[v,start,end]:adj[u]){
                int depart=max(time,start);
                if(depart>end) continue;
                long long arrival=depart+1;
                if(arrival<dist[v]){
                    dist[v]=arrival;
                    pq.push({arrival,v});
                }
            }
        }
        return -1;
    }
};
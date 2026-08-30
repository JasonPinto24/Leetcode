class Solution {
public:
    void bfs(int node,vector<int> &dist,vector<int> &edges){
        queue<int> q;
        q.push(node);
        dist[node]=0;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            int next=edges[n];
            if(next!=-1){
                if(dist[next]>dist[n]+1){
                    dist[next]=dist[n]+1;
                    q.push(next);
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);
        bfs(node1,dist1,edges);
        bfs(node2,dist2,edges);
        int best=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(dist1[i]==INT_MAX || dist2[i]==INT_MAX) continue;
            int curr=max(dist1[i],dist2[i]);
            if(curr<best){
                best=curr;
                ans=i;
            }
        }
        return ans;
    }
};
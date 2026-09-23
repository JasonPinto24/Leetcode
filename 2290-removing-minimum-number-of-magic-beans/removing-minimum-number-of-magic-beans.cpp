class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        int n=beans.size();
        vector<long long> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+beans[i];
        }
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            long long x=beans[i];
            long long left=prefix[i];
            long long right=(prefix[n]-prefix[i+1])-x*(n-i-1);
            long long total=left+right;
            ans=min(ans,total);
        }
        return ans;
    }
};
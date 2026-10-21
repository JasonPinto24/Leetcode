class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        long long ans=0;
        vector<int> starts,ends;
        for(auto &it:intervals){
            starts.push_back(it[0]);
            ends.push_back(it[1]);
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        int ended=0;
        for(int i=0;i<n;i++){
            while(ended<n && ends[ended]<starts[i]){
                ended++;
            }
            ans+=i-ended;
        }
        return ans;
    }
};
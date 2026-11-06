class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(),
        [](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        vector<pair<int,int>>q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        unordered_map<int,int>freq;
        vector<int> ans(queries.size());
        int left=0;
        int right=0;
        for(auto &[time,index]:q){
            while(right<logs.size() && logs[right][1]<=time){
                freq[logs[right][0]]++;
                right++;
            }
            while(left<right && logs[left][1]<time-x){
                freq[logs[left][0]]--;
                if(freq[logs[left][0]]==0){
                    freq.erase(logs[left][0]);
                }
                left++;
            }
            ans[index]=n-freq.size();
        }
        return ans;

    }
};
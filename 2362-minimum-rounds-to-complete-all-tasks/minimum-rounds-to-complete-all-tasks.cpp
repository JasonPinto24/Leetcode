class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mpp;
        for(int x:tasks) mpp[x]++;
        int ans=0;
        for(auto &[diff,freq]:mpp){
            if(freq==1) return -1;
            ans+=freq/3;
            if(freq%3==2) ans++;
            else if(freq%3==1) ans++;

        }
        return ans;
    }
};
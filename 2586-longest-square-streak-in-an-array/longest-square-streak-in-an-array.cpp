class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long>st;
        for(int x:nums) st.insert(x);
        int ans=-1;
        for(int x:nums){
            if(x==1) continue;
            long long curr=x;
            int len=1;
            while(st.count(curr*curr)){
                curr=curr*curr;
                len++;
            }
            if(len>=2) ans=max(len,ans);
        }
        return ans;
    }
};
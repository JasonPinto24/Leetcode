class Solution {
public:
    int solve(int i,vector<int> &arr,vector<int> &dp){
        if(i>=arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=arr[i]+solve(i+2,arr,dp);
        int nottake=solve(i+1,arr,dp);
        return dp[i]=max(take,nottake);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> arr(maxi+1,0);
        for(int x:nums){
            arr[x]+=x;
        }
        vector<int> dp(maxi+1,-1);
        return solve(0,arr,dp);
    }
};
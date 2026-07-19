class Solution {
public:
    int solve(int i,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(i==0){
            if(target==0 && nums[i]==0) return 2;
            if(target==nums[i] || target==0) return 1;
            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int take=0;
        if(nums[i]<=target) take=solve(i-1,target-nums[i],nums,dp);
        int nottake=solve(i-1,target,nums,dp);
        return dp[i][target]=take+nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++) sum+=nums[i];
        if(abs(target)>sum) return 0;
        if((sum+target)%2) return 0;
        int p=(sum+target)/2;
        vector<vector<int>> dp(n,vector<int>(p+1,-1));
        return solve(n-1,p,nums,dp);

    }
};
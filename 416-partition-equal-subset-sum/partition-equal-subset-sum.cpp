class Solution {
public:
    int solve(int i,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(i==0) return (nums[i]==target||target==0);
        if(dp[i][target]!=-1) return dp[i][target];
        bool nottake=solve(i-1,target,nums,dp);
        bool take=false;
        if(nums[i]<=target) take=solve(i-1,target-nums[i],nums,dp);
        return dp[i][target]=take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(sum%2) return false;
        int target=sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,nums,dp);
    }
};
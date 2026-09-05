class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int target,vector<int> &nums){
        if(i==0){
            if(target==0) return 0;
            if(target==nums[0]) return 1;
            return INT_MIN;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int skip=solve(i-1,target,nums);
        int take=INT_MIN;
        if(nums[i]<=target){
            take=1+solve(i-1,target-nums[i],nums);
        }
        return dp[i][target]=max(take,skip);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        dp.assign(n,vector<int>(target+1,-1));
        int ans=solve(n-1,target,nums);
        return ans>0 ? ans:-1;
    }
};
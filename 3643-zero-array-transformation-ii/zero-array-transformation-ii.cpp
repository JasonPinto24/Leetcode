class Solution {
public:
    bool check(vector<int> &nums,vector<vector<int>> &queries,int k){
        int n=nums.size();
        vector<int> diff(n+1,0);
        for(int i=0;i<k;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int val=queries[i][2];
            diff[l]+=val;
            diff[r+1]-=val;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=diff[i];
            if(sum<nums[i]) return false;

        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low=0;
        int high=queries.size();
        if(!check(nums,queries,high)) return -1;
        while(low<high){
            int mid= low+(high-low)/2;
            if(check(nums,queries,mid)) high=mid;
            else low=mid+1;
        }
        return low;
    }
};
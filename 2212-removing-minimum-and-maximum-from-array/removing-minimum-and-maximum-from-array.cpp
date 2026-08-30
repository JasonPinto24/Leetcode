class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int mnidx=-1;
        int mxidx=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==mn) mnidx=i;
            if(nums[i]==mx) mxidx=i;
        }
        int left=min(mnidx,mxidx);
        int right=max(mxidx,mnidx);
        int op1=right+1;
        int op2=n-left;
        int op3=(left+1) + (n-right);
        return min({op1,op2,op3});
    }
};
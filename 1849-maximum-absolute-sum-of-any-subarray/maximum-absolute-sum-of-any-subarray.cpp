class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum=0;
        int minsum=0;
        int ans=0;
        for(int x:nums){
            maxsum=max(maxsum+x,x);
            minsum=min(minsum+x,x);
            ans=max(ans,abs(maxsum));
            ans=max(ans,abs(minsum));
        }
        return ans;
    }
};
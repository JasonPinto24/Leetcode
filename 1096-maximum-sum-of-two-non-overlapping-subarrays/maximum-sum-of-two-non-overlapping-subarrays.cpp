class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        int ans=0;
        int bestfirst=0;
        for(int i=firstLen;i+secondLen<=n;i++){
            int firstsum=prefix[i]-prefix[i-firstLen];
            bestfirst=max(firstsum,bestfirst);
            int secondsum=prefix[i+secondLen]-prefix[i];
            ans=max(ans,bestfirst+secondsum);
        }
        int bestsecond=0;
        for(int i=secondLen;i+firstLen<=n;i++){
            int secondsum=prefix[i]-prefix[i-secondLen];
            bestsecond=max(bestsecond,secondsum);
            int firstsum=prefix[i+firstLen]-prefix[i];
            ans=max(firstsum+bestsecond,ans);
        }
        return ans;
    }
};
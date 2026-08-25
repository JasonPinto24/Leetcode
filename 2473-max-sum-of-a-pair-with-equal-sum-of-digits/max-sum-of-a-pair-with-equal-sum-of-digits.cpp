class Solution {
public:
    int digisum(int n){
        int ans=0;
        while(n){
            ans+=n%10;
            n/=10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int ans=-1;
        for(int x:nums){
            int sum=digisum(x);
            if(mpp.count(sum)){
                ans=max(ans,x+mpp[sum]);
            }
            mpp[sum]=max(mpp[sum],x);
        }
        return ans;
    }
};
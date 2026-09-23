class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int maxlen=0;
        int totalsum=0;
        for(int x:nums) totalsum+=x;
        int target=totalsum-x;
        if(target==0) return n;
        int prefix=0;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            if(mpp.find(prefix-target)!=mpp.end()){
                int len=i-mpp[prefix-target];
                maxlen=max(maxlen,len);
            }
            if(mpp.find(prefix)==mpp.end()) mpp[prefix]=i;
        }
        if(maxlen==0) return -1;
        return n-maxlen;
    }
};
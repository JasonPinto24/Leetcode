class Solution {
public:
    const int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        long long ans=0;
        int even=1;
        int odd=0;
        int prefix=0;
        for(int x:arr){
            prefix+=x;
            if(prefix%2==1){
                ans+=even;
                odd++;
            }
            else{
                ans+=odd;
                even++;
            }
            ans%=mod;
        }
        return ans;
    }
};
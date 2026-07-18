class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small=*min_element(nums.begin(),nums.end());
        int big=*max_element(nums.begin(),nums.end());
        int gcd=1;
        for(int i=1;i<=big;i++){
            if(small%i==0 && big%i==0) gcd=max(gcd,i);
        }
        return gcd;
    }
};
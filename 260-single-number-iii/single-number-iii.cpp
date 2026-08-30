class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorall=0;
        for(int x:nums) xorall^=x;
        long long bit=(xorall) & (-xorall);
        int a=0;
        int b=0;
        for(int x:nums){
            if(x & bit) a^=x;
            else b^=x;
        }
        return {a,b};
    }
};
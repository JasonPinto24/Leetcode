class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int groups=0;
        int mx=-1;
        for(int x:nums){
            if(x>=mx){
                groups++;
                mx=x;
            }
        }
        return groups;
    }
};
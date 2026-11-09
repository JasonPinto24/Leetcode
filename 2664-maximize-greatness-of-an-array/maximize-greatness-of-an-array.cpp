class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        while(j<n){
            if(nums[j]>nums[i]){
                i++;
                ans++;
            }
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    long long count(vector<int> &nums,int x){
        long long left=0;
        long long right=nums.size()-1;
        long long ans=0;
        while(left<right){
            if(nums[left]+nums[right]<=x){
                ans+=right-left;
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return count(nums,upper) - count(nums,lower-1);
    }
};
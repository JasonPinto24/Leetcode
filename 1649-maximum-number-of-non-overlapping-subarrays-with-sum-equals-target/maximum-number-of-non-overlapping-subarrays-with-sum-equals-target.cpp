class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int>seen;
        seen.insert(0);
        int sum=0;
        int ans=0;
        for(int x:nums){
            sum+=x;
            if(seen.count(sum-target)){
                ans++;
                seen.clear();
                seen.insert(0);
                sum=0;
            }else{
                seen.insert(sum);
            }
        }
        return ans;
    }
};
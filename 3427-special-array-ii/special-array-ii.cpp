class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> bad(n-1,0);
        for(int i=0;i<n-1;i++){
            if(nums[i]%2==nums[i+1]%2){
                bad[i]=1;
            }
            
        }
        vector<int> prefix(n,0);
        for(int i=0;i<n-1;i++){
            prefix[i+1]=prefix[i]+bad[i];
        }
        vector<bool>ans;
        for(auto &q:queries){
            int l=q[0];
            int r=q[1];
            int sum=prefix[r]-prefix[l];
            ans.push_back(sum==0);
        }
        return ans;
    }
};
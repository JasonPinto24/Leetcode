class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> nums;
        for(int i=1;i<=m;i++){
            nums.push_back(i);
        }
        vector<int> ans;
        for(int q:queries){
            int pos=0;
            while(nums[pos]!=q) pos++;
            ans.push_back(pos);
            nums.erase(nums.begin()+pos);
            nums.insert(nums.begin(),q);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> freq(101,0);
        vector<int> ans;
        int n=nums.size();
        for(int x:nums){
            freq[x]++;
        }
        //vector<int> ans;
        while(true){
            bool found=false;
            for(int i=0;i<101;i++){
                if(freq[i]>0){
                    ans.push_back(i);
                    freq[i]--;
                    found=true;
                }
            }
            if(!found) break;
        }
        return ans;
    }
};
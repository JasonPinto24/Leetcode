class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        int reach=0;
        int i=0;
        int ans=0;
        while(reach<target){
            if(i<coins.size() && coins[i]<=reach+1){
                reach+=coins[i];
                i++;
            }
            else{
                ans++;
                reach+=reach+1;
            
            }
        }
        return ans;
    }
};
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int wins=0;
        int mx = *max_element(arr.begin(), arr.end());
        while(wins<k){
            if (arr[0] == mx)
                return arr[0];
            if(arr[0]>arr[1]){
                wins++;
                int loser=arr[1];
                arr.erase(arr.begin()+1);
                arr.push_back(loser);
            }else{
                wins=1;
                int loser=arr[0];
                arr.erase(arr.begin());
                arr.push_back(loser);
            }
        }
        return arr[0];
    }
};
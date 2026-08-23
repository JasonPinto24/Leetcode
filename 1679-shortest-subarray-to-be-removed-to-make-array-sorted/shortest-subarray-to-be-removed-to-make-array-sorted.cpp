class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int left=0;
        int n=arr.size();
        while(left+1<n && arr[left+1]>=arr[left]) left++;
        if(left==n-1) return 0;
        int right=n-1;
        while(right-1>=0 && arr[right-1]<=arr[right]) right--;
        int ans=n-left-1;
        ans=min(ans,right);
        int i=0;
        int j=right;
        while(i<=left && j<n){
            if(arr[i]<=arr[j]){
                ans=min(ans,j-i-1);
                i++;
            }else{
                j++;
            }
        }
        return ans;

        
    }
};
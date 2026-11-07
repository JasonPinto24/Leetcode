class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int alternating=1;
        int ans=0;
        for(int i=1;i<n+k-1;i++){
            if(colors[i%n]==colors[(i-1)%n]) alternating=1;
            else alternating++;
            if(alternating>=k) ans++;
        }
        return ans;
    }
};
class Solution {
public:
    // int solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
    //     if(i==0 && j==0) return 0;
    //     if(i==0){
    //         return dp[i][j]=s2[j-1]+solve(i,j-1,s1,s2,dp);
    //     }
    //     if(j==0) return dp[i][j]=s1[i-1]+solve(i-1,j,s1,s2,dp);
    //     if(s1[i-1]==s2[j-1]) return dp[i][j]=solve(i-1,j-1,s1,s2,dp);
    //     int del1=s1[i-1]+solve(i-1,j,s1,s2,dp);
    //     int del2=s2[j-1]+solve(i,j-1,s1,s2,dp);
    //     return dp[i][j]=min(del1,del2);
    // }
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // return solve(m,n,s1,s2,dp);
        for(int i=1;i<=m;i++){
            dp[i][0]=dp[i-1][0]+s1[i-1];
        }
        for(int j=1;j<=n;j++){
            dp[0][j]=dp[0][j-1]+s2[j-1];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=min(
                        s1[i-1]+dp[i-1][j],
                        s2[j-1]+dp[i][j-1]
                    );
                }
            }
        }
        return dp[m][n];
    }
};
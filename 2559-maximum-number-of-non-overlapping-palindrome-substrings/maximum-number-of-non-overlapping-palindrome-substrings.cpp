class Solution {
public:
    int maxPalindromes(string s, int k) {

        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int center = n - 1; center >= 0; center--) {

            dp[center] = max(dp[center], dp[center + 1]);

            // Odd length palindromes
            for (int l = center, r = center; l >= 0 && r < n && s[l] == s[r]; l--, r++) {

                if (r - l + 1 >= k) {
                    dp[l] = max(dp[l], 1 + dp[r + 1]);
                    break;
                }
            }

            // Even length palindromes
            for (int l = center, r = center + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {

                if (r - l + 1 >= k) {
                    dp[l] = max(dp[l], 1 + dp[r + 1]);
                    break;
                }
            }
        }

        return dp[0];
    }
};
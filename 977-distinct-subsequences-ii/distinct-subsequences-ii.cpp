class Solution {
public:
    int distinctSubseqII(string s) {

        const long long MOD = 1e9 + 7;

        vector<long long> dp(26, 0);

        long long total = 0;

        for (char c : s) {

            int x = c - 'a';

            // All existing subsequences + empty subsequence
            // can have c appended.
            long long newSubseq = (total + 1) % MOD;

            // Replace old subsequences ending in c
            // because they are duplicates.
            total = (total - dp[x] + newSubseq) % MOD;

            if (total < 0)
                total += MOD;

            dp[x] = newSubseq;
        }

        return total;
    }
};
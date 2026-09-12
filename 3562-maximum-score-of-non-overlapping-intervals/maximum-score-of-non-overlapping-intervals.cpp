class Solution {
public:
    using ll = long long;

    struct State {
        ll score;
        vector<int> indices;
    };

    int n;
    vector<vector<int>> arr;
    vector<vector<int>> nextIdx;
    vector<vector<State>> dp;
    vector<vector<bool>> vis;

    State better(State a, State b) {
        if (a.score != b.score)
            return (a.score > b.score ? a : b);

        sort(a.indices.begin(), a.indices.end());
        sort(b.indices.begin(), b.indices.end());

        return (a.indices < b.indices ? a : b);
    }

    State solve(int i, int k) {
        if (i >= n || k == 0)
            return {0, {}};

        if (vis[i][k])
            return dp[i][k];

        vis[i][k] = true;

        // Skip current interval
        State skip = solve(i + 1, k);

        // Take current interval
        State take = solve(nextIdx[i][0], k - 1);
        take.score += arr[i][2];
        take.indices.push_back(arr[i][3]);

        return dp[i][k] = better(skip, take);
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        // Store original index
        arr.clear();

        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by starting position
        sort(arr.begin(), arr.end());

        nextIdx.assign(n, vector<int>(1, n));

        // Find next non-overlapping interval
        vector<int> starts(n);

        for (int i = 0; i < n; i++)
            starts[i] = arr[i][0];

        for (int i = 0; i < n; i++) {
            int pos = upper_bound(
                starts.begin(),
                starts.end(),
                arr[i][1]
            ) - starts.begin();

            nextIdx[i][0] = pos;
        }

        dp.assign(n + 1, vector<State>(5));
        vis.assign(n + 1, vector<bool>(5, false));

        State ans = solve(0, 4);

        sort(ans.indices.begin(), ans.indices.end());

        return ans.indices;
    }
};
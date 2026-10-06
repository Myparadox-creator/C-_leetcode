class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1000000007;

        vector<vector<long long>> dp(
            n, vector<long long>(k + 1, 0)
        );

        vector<vector<long long>> open(
            n, vector<long long>(k + 1, 0)
        );

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < n; i++) {

            for (int j = 1; j <= k; j++) {

                // Skip point i
                dp[i][j] = dp[i - 1][j];

                // Start a segment at i-1
                open[i][j] = dp[i - 1][j - 1];

                // Continue a segment that was already open
                if (i >= 2) {
                    open[i][j] += open[i - 1][j];
                    open[i][j] %= MOD;
                }

                // Close the segment at i
                dp[i][j] += open[i][j];
                dp[i][j] %= MOD;
            }
        }

        return dp[n - 1][k];
    }
};
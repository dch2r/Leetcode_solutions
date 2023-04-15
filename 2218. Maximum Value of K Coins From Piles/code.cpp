class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int dp[2001] = {}, N = piles.size();
        for (int i = 0; i < N; ++i) {
            for (int j = k; j >= 1; --j) {
                for (int t = 1, sum = 0; t <= j && t <= piles[i].size(); ++t) {
                    sum += piles[i][t - 1];
                    dp[j] = max(dp[j], dp[j - t] + sum);
                }
            }
        }
        return dp[k];
    }
};

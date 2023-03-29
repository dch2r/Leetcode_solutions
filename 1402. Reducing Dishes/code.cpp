class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, INT_MIN));
        return max(0, dfs(satisfaction, 0, 1, dp));
    }

private:
    int dfs(const vector<int>& v, int index, int t, vector<vector<int>>& dp){

        if(index == v.size()) return 0;
        if(dp[index][t] != INT_MIN) return dp[index][t];
        return dp[index][t] = max(t * v[index] + dfs(v, index + 1, t + 1, dp),
                                  dfs(v, index + 1, t, dp));
    }
};

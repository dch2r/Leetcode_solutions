class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() && nums2.empty()) 
				return 0;
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = nums1[i] == nums2[j];
        if (i > 0 && j > 0) dp[i][j] = dp[i][j] + dp[i - 1][j - 1];
        if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
      }
    }
    return dp.back().back();
    }
};

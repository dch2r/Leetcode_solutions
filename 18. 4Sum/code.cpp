class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (j > (i + 1) && nums[j-1] == nums[j]) {
                    continue;
                }
                int l = j + 1, r = n - 1;
                int partial_sum = nums[i] + nums[j];
                while (l < r) {
                    int sum = partial_sum + nums[l] + nums[r];
                    if (sum < target) {
                        l++;
                    } else if (sum > target) {
                        r--;
                    } else {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while ((l + 1) < nums.size() && nums[l] == nums[l+1]) l++;
                        l++;
                        while ((r - 1) >= 0 && nums[r] == nums[r - 1]) r--;
                        r--;
                    }
                }
            }
        }
        return result;
    }
};

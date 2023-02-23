class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        while(left < right){
            ans = max(ans, min(height[left], height[right])*(right-left));
            if(height[left] < height[right]){
                left += 1;
            } else {
                right -= 1;
            }
        }
        return ans;
    }
};

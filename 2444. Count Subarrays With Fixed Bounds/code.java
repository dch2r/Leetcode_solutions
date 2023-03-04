class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        
    int n = nums.length;
    int startInd = 0;
    int lastMinInd = -1;
    int lastMaxInd = -1;
    long res = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] < minK || nums[i] > maxK){
            lastMinInd = lastMaxInd = -1;
            startInd = i + 1;
            } 
            if(nums[i] == minK){
                lastMinInd = i;
                }
                if(nums[i] == maxK){
                    lastMaxInd = i;
                    }
                    res += Math.max(0L, Math.min(lastMinInd, lastMaxInd) - startInd + 1);
                    }
                    return res;
                    }
                }
    

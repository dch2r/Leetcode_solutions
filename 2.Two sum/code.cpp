/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.


Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> res;
        unordered_map<int,int> n;
        for(int i=0;i<nums.size();i++){
            if(n.find(target-nums[i]) != n.end()){
                res.push_back(n[target-nums[i]]); 
                res.push_back(i);
                return res;
            }
            n[nums[i]]=i;                                                                                                                                           
            
        }
        return res;
    }
};

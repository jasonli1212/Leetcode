/*
    This Solution can be optimized by using only 3 variables instead of an array, Since we only need to check the previous 3 values.
*/


class Solution {
public:
    bool validPartition(std::vector<int>& nums) {
        // To record if the subarray from 0 to i is valid
        bool dp[nums.size()];
        if (nums.size() <= 1) {
            return false;
        }

        dp[0] = false;
        dp[1] = nums[0] == nums[1];

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = false;
            // using to value i - 1 to form a valid subarray, so check if the subarray from 0 to i - 2 is valid
            if (nums[i] == nums[i - 1] && dp[i - 2]) {
                dp[i] = true;
            }
            
            // using to value i - 1 and i - 2 to form a valid subarray, so check if the subarray from 0 to i - 3 is valid
            if (i - 2 >= 0 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2] && (i - 3 < 0 || dp[i - 3])) {
                dp[i] = true;
            }

            // using to value i - 1 and i - 2 to form a valid subarray, so check if the subarray from 0 to i - 3 is valid
            if (i - 2 >= 0 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1 && (i - 3 < 0 || dp[i - 3])) {
                dp[i] = true;
            }
        }
        return dp[nums.size()-1];
    }
};
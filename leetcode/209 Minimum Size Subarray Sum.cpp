// https://leetcode.com/problems/minimum-size-subarray-sum/solutions/4521243/c-sliding-window-solution/

class Solution {
private:
    const int INITIAL_VALUE = 100001;

public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = nums[0] >= target ? 1 : INITIAL_VALUE;
        int pointer = 0;
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];

            while (sum - nums[pointer] >= target) {
                sum -= nums[pointer];
                pointer++;
            }

            if (sum >= target) {
                ans = std::min(ans, i - pointer + 1);
            }
        }

        return ans == INITIAL_VALUE ? 0 : ans;
    }
};

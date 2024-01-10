// https://leetcode.com/problems/summary-ranges/solutions/4540042/c-easy-solution/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};

        std::vector<std::string> ans;
        
        int start = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                if (start == nums[i - 1]) {
                    ans.push_back(std::to_string(start));
                } else {
                    ans.push_back(std::to_string(start) + "->" + std::to_string(nums[i - 1]));
                }
                start = nums[i];
            }
        }

        if (start == nums.back()) {
            ans.push_back(std::to_string(start));
        } else {
            ans.push_back(std::to_string(start) + "->" + std::to_string(nums.back()));
        }

        return ans;
    }
};

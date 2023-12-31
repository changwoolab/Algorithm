// https://leetcode.com/problems/longest-consecutive-sequence/solutions/4483971/c-unordered-map-solution/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> map;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = true;
        }

        int max = 0;
        for (auto kv : map) {
            int value = kv.first;
            if (map.find(value - 1) == map.end()) {
                int y = value + 1;
                while (map.find(y) != map.end()) y++;
                max = max > y - value ? max : y - value;
            }
        }

        return max;
    }
};

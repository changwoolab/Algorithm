// https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/4523978/c-unordered-map-solution/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int left = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            char chr = s[i];

            bool notFound = map.find(chr) == map.end();
            bool isOutdated = map[chr] < left;
            if (notFound || isOutdated) {
                ans = std::max(ans, i - left + 1);    
            } else {
                left = map[chr] + 1;
            }

            map[chr] = i;
        }

        return ans;
    }
};

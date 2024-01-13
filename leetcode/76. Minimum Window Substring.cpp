// https://leetcode.com/problems/minimum-window-substring/solutions/4558079/c-easy-solution-using-2-hashmap/

class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";

        unordered_map<char, int> targetMap;
        for (int i = 0; i < t.size(); i++) {
            targetMap[t[i]]++;
        }

        unordered_map<char, int> countMap;
        int tSize = t.size();
        int left = 0;
        int letterCounter = 0;
        for (int right = 0; right < s.size(); right++) {
            if (targetMap.find(s[right]) != targetMap.end()) {
                countMap[s[right]]++;
                if (countMap[s[right]] <= targetMap[s[right]]) {
                    letterCounter++;
                }
            }

            bool isAllFound = letterCounter >= tSize;
            if (isAllFound) {
                // If the answer is found, try to minimize the window size
                while ((targetMap.find(s[left]) == targetMap.end() 
                            || countMap[s[left]] > targetMap[s[left]]) && left < right) {
                    countMap[s[left]]--;
                    left++;
                }

                string temp = s.substr(left, right - left + 1);
                ans = ans == "" || ans.size() > temp.size() ? temp : ans;
            }
        }

        return ans;
    }
};

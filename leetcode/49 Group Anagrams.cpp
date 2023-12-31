class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(int i = 0; i < strs.size(); i++) {
            int count[26] = { 0 };

            for (int j = 0; j < strs[i].size(); j++) {
                count[strs[i][j] - 'a']++;
            }

            string encode = "";
            for (int j = 0; j < 26; j++) {
                encode += char('a' + j) + char(count[j]);
            }

            if (map.find(encode) == map.end()) {
                vector<string> vec;
                map[encode] = vec;
            }

            map[encode].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for (auto kv : map) {
            ans.push_back(kv.second);
        }

        return ans;
    }
};

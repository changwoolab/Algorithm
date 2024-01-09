// https://leetcode.com/problems/substring-with-concatenation-of-all-words/solutions/4534615/c-easy-solution-with-two-hashmap/

class Solution {
private:
    unordered_map<string, int> makeMapFromWords(vector<string>& words) {
        unordered_map<string, int> map;

        for (auto w : words) {
            map[w]++;
        }

        return map;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordSize = words[0].size();
        int slideSize = wordSize * words.size();
        vector<int> ans;
        unordered_map<string, int> wordMap = makeMapFromWords(words);

        string temp = "";
        for (int i = 0; i < s.size() - slideSize + 1; i++) {
            string target = s.substr(i, slideSize);
            unordered_map<string, int> tempMap;

            for (int j = 0; j < target.size(); j += wordSize) {
                string tempStr = target.substr(j, wordSize);
                tempMap[tempStr]++;
            }

            bool isAnswer = true;
            for (auto kv : wordMap) {
                if (kv.second != tempMap[kv.first]) {
                    isAnswer = false;
                    break;
                }
            }

            if (isAnswer) ans.push_back(i);
        }

        return ans;
    }
};

// https://leetcode.com/problems/valid-parentheses/solutions/4569478/c-solution-using-stack-and-hashmap/

class Solution {
private:
    unordered_map<char, char> pairs = {
        { '(', ')' },
        { '{', '}' },
        { '[', ']' }
    };

public:
    bool isValid(string s) {
        vector<char> stack;

        for (char c : s) {
            if (!stack.empty()) {
                char stackBack = stack.back();

                if (pairs.find(stackBack) != pairs.end() && pairs[stackBack] == c) {
                    stack.pop_back();
                    continue;
                }
            }

            stack.push_back(c);
        }

        return stack.empty();
    }
};

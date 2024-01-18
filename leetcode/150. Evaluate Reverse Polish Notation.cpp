// https://leetcode.com/problems/evaluate-reverse-polish-notation/solutions/4585888/c-easy-solution-using-stack/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int)>> map = {
            { "+", [] (int a, int b) { return a + b; }},
            { "-", [] (int a, int b) { return a - b; }},
            { "*", [] (int a, int b) { return a * b; }},
            { "/", [] (int a, int b) { return a / b; }},
        };

        stack<int> stack;
        for (string token : tokens) {
            if (map.find(token) == map.end()) {
                stack.push(stoi(token));
            } else {
                int v2 = stack.top();
                stack.pop();
                int v1 = stack.top();
                stack.pop();
                stack.push(map[token](v1, v2));
            }
        }

        assert(stack.size() == 1);
        return stack.top();
    }
};

// https://leetcode.com/problems/simplify-path/solutions/4575649/c-easy-solution-using-stack/

class Solution {
private:
    vector<string> split(const string& str, char delimiter) {
        stringstream ss(str);
        string token;
        vector<string> tokens;
        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

public:
    string simplifyPath(string path) {
        vector<string> stack = { "root" };

        for (string s : split(path, '/')) {
            if (s == "" || s == ".") {
                continue;
            } else if (s == "..") {
                if (stack.back() != "root") stack.pop_back();
            } else { 
                stack.push_back(s);
            }
        }

        string ans = "/";
        for (int i = 1; i < stack.size(); i++) {
            ans += stack[i];
            if (i != stack.size() - 1) {
                ans += "/";
            }
        }

        return ans;
    }
};

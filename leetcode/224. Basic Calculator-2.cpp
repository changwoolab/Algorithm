class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int sign = 1;

        stack<int> st;
        st.push(1);

        int temp = 0;
        for (char c : s) {
            if (c == '(') {
                st.push(sign);
            } else if (c == ')') {
                st.pop();
                sign = st.top();
            } else if (c >= '0' && c <= '9') {
                temp = temp * 10 + sign * (c - '0');
            } else if (c == '+') {
                sign = 1 * st.top();
            } else if (c == '-') {
                sign = -1 * st.top();
            }
            
            if (!(c >= '0' && c <= '9')) {
                ans += temp;
                temp = 0;
            }
        }

        ans += temp;
        return ans;
    }
};

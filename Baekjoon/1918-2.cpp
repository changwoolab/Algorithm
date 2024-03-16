#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <unordered_map>
#include <map>
#include <list>
#include <stack>
#define NOT_DEFINED 987654321

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  string s;
  cin >> s;

  stack<char> st;
  string ans = "";

  for (char c : s) {
    if (c == '+' || c == '-') {
      while (!st.empty() && st.top() != '(') {
        ans += st.top();
        st.pop();
      }
      st.push(c);
    } else if (c == '*' || c == '/') {
      while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
        ans += st.top();
        st.pop();
      }
      st.push(c);
    } else if (c == '(') {
      st.push(c);
    } else if (c == ')') {
      while (!st.empty() && st.top() != '(') {
        ans += st.top();
        st.pop();
      }
      st.pop();
    } else {
      // 알파벳들
      ans += c;
    }
  }

  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  cout << ans;
}

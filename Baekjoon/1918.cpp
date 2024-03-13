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

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  string s;
  cin >> s;

  int i = 0;
  while (i < s.size()) {
    if (s[i] == '*' || s[i] == '/') {
      int left = i-1, right = i+1;
      int st = 0;
      if (left >= 0 && s[left] == ')') st++;
      while (left >= 0 && st) {
        left--;
        if (s[left] == '(') st--;
        else if (s[left] == ')') st++;
      }

      st = 0;
      if (right < s.size() && s[right] == '(') st++;
      while (right < s.size() && st) {
        right++;
        if (s[right] == ')') st--;
        else if (s[right] == '(') st++;
      }

      s = 
        s.substr(0, left) + '(' 
        + s.substr(left, right - left + 1) + ')' 
        + s.substr(right+1, s.size() - right);

      i++;
    }

    i++;
  }

  i = 0;
  while (i < s.size()) {
    if (s[i] == '+' || s[i] == '-') {
      int left = i-1, right = i+1;
      int st = 0;
      if (left >= 0 && s[left] == ')') st++;
      while (left >= 0 && st) {
        left--;
        if (s[left] == '(') st--;
        else if (s[left] == ')') st++;
      }

      st = 0;
      if (right < s.size() && s[right] == '(') st++;
      while (right < s.size() && st) {
        right++;
        if (s[right] == ')') st--;
        else if (s[right] == '(') st++;
      }

      s = 
        s.substr(0, left) + '(' 
        + s.substr(left, right - left + 1) + ')' 
        + s.substr(right+1, s.size() - right);

      i++;
    }

    i++;
  }

  string ans = "";
  stack<char> st;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (c == '+' || c == '-') {
      st.push(c);
    } else if (c == '*' || c == '/') {
      if (i+1 < s.size() && s[i+1] != '(') {
        ans += s[i+1];
        ans += s[i];
        i++;
      } else {
        st.push(c);
      }
    } else if (c == '(') {
      st.push(c);
    } else if (c == ')') {
      while (!st.empty() && st.top() != '(') {
        ans += st.top();
        st.pop();
      }
      st.pop();
    } else {
      ans += c;
    }
  }

  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  cout << ans;
}

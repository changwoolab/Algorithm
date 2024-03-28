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
#define pi pair<int, int>
#define NOT_DEFINED 987654321

using namespace std;

string str;
string bomb;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> str;
  cin >> bomb;

  stack<int> st;
  string bob;
  for (int i = 0; i < str.size(); i++) {
    st.push(str[i]);

    if (str[i] == bomb[bomb.size()-1] && st.size() >= bomb.size()) {
      string tmp;

      for (int j = 0; j < bomb.size(); j++) {
        tmp += st.top();
        st.pop();
      }

      reverse(tmp.begin(), tmp.end());

      if (tmp != bomb) {
        for (int j = 0; j < tmp.size(); j++) {
          st.push(tmp[j]);
        }
      }
    }
  }

  string ans;
  while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }
  reverse(ans.begin(), ans.end());

  if (ans.empty()) {
    cout << "FRULA";
  } else {
    cout << ans;
  }
}

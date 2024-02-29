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

  int q;
  cin >> q;

  map<string, priority_queue<int> > m;
  long long ans = 0;

  for (int i = 0; i < q; i++) {
    int op;
    string info;
    int k;

    cin >> op >> info >> k;
    
    if (op == 1) {
      if (!m.count(info)) {
        priority_queue<int> pq;
        m[info] = pq;
      }

      for (int j = 0; j < k; j++) {
        int value;
        cin >> value;
        m[info].push(value);
      }
    } else {
      if (m.count(info)) {
        if (m[info].size() < k) {
          while (m[info].size()) {
            ans += m[info].top();
            m[info].pop();
          }
        } else {
          for (int j = 0; j < k; j++) {
            ans += m[info].top();
            m[info].pop();
          }
        }
      }
    }
  }

  cout << ans;
}

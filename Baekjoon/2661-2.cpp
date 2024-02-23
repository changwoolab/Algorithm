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

using namespace std;

int n;
string ans = "";

void solve(string curr) {
  if (ans != "") return;

  for (int len = 1; len < curr.size(); len++) {
    int right = curr.size()-1;
    int left = right - len;
    if (left < 0) break;

    int cnt = 0;
    for (int i = 0; i < len; i++) {
      if (curr[right - i] == curr[left - i]) {
        cnt++;
      }
    }

    // 같은게 존재하면 불가능
    if (cnt == len) return;
  }

  if (curr.size() == n) ans = curr;

  for (char i = '1'; i <= '3'; i++) {
    solve(curr + i);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> n;

  solve("");

  cout << ans;
}

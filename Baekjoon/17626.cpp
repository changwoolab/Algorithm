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

int n;
int ans = NOT_DEFINED;

void dfs(int curr, int currSum, int depth) {
  if (currSum > n) return;
  if (currSum == n) {
    ans = min(ans, depth);
    return;
  }
  if (depth >= 3) return;

  for (int i = 1; i < 225; i++) {
    dfs(i, currSum + i*i, depth + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> n;

  dfs(0, 0, 0);

  if (ans == NOT_DEFINED) cout << 4;
  else cout << ans;
}

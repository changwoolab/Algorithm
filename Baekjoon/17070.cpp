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
int arr[16][16];
int ans = 0;

// (왼쪽부분 좌표, 오른쪽부분 좌표)
// 가로로 있는 경우: (0, 1, 0, 1) (0, 1, 1, 1)
// 세로로 있는 경우: (1, 0, 1, 0) (1, 0, 1, 1)
// 대각선: (1, 1, 0, 1) (1, 1, 1, 0) (1, 1, 1, 1)
void dfs(int lr, int lc, int rr, int rc) {
  if (!(lr >= 0 && lr < n && rr >= 0 && rc < n)) {
    return;
  }

  if (arr[lr][lc] == 1 || arr[rr][rc] == 1) {
    return;
  }

  // 대각선으로 있는 경우에는, 현재 위치의 위와 왼쪽이 벽이 이나어야 함
  if (lr != rr && lc != rc) {
    if (
      (rr-1 >= 0 && arr[rr-1][rc] == 1) || 
      (rc-1 >= 0 && arr[rr][rc-1] == 1)) {
        return;
    }
  }

  if (rr == n-1 && rc == n-1) {
    ans++;
    return;
  }

  // 가로로 있는 경우
  if (lr == rr) {
    dfs(lr, lc+1, rr, rc+1);
    dfs(lr, lc+1, rr+1, rc+1);
  }
  // 세로로 있는 경우
  else if (lc == rc) {
    dfs(lr+1, lc, rr+1, rc);
    dfs(lr+1, lc, rr+1, rc+1);
  }
  // 대각선으로 있는 경우
  else {
    dfs(lr+1, lc+1, rr, rc+1);
    dfs(lr+1, lc+1, rr+1, rc);
    dfs(lr+1, lc+1, rr+1, rc+1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  dfs(0, 0, 0, 1);

  cout << ans;
}

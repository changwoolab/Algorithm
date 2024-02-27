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
#define NOANS 1005

using namespace std;

const int di[4] = { 0, 0, 1, -1 };
const int dj[4] = { 1, -1, 0, 0 };

int ans = 1000;
int n, m;
bool visited[30][30];
int targetDepth;

bool check(int i, int j) {
  return !(i < 0 || j < 0 || i >= n || j >= m || visited[i][j]);
}

void solve(int i, int j, int direction, int depth, int dirChangeCnt) {
  if (depth == targetDepth) {
    ans = min(ans, dirChangeCnt);
    return;
  }

  visited[i][j] = true;

  int ni = i + di[direction];
  int nj = j + dj[direction];

  if (check(ni, nj)) {
    solve(ni, nj, direction, depth+1, dirChangeCnt);
  } else {
    for (int nd = 0; nd < 4; nd++) {
      if (nd == direction) continue;
      ni = i + di[nd];
      nj = j + dj[nd];
      if (check(ni, nj)) {
        solve(ni, nj, nd, depth+1, dirChangeCnt+1);
      }
    }
  }

  visited[i][j] = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  int t = 0;
  while ((cin >> n >> m)) {
    targetDepth = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        if (s[j] == '*') {
          visited[i][j] = true;
        } else {
          targetDepth++;
          visited[i][j] = false;
        }
      }
    }

    ans = NOANS;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int dir = 0; dir < 4; dir++) {
          if (!visited[i][j] && check(i + di[dir], j + dj[dir])) {
            solve(i, j, dir, 1, 1);
          } else if (!visited[i][j] && !check(i + di[dir], j + dj[dir])) {
            solve(i, j, dir, 1, 0);
          }
        }
      }
    }
    cout << "Case " << ++t << ": " << (ans == NOANS ? -1 : ans) << '\n';
  }
}

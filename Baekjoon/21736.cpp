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

int n, m;
char campus[601][601];
bool visited[601][601] = {0};
pi me;

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> campus[i][j];
      if (campus[i][j] == 'I') {
        me = { i, j };
      }
    }
  }

  int ans = 0;
  queue<pi> q;
  q.push(me);
  while (!q.empty()) {
    pi curr = q.front();
    q.pop();

    if (visited[curr.first][curr.second]) continue;
    visited[curr.first][curr.second] = true;
    if (campus[curr.first][curr.second] == 'P') ans++;

    for (int i = 0; i < 4; i++) {
      int nr = curr.first + dr[i];
      int nc = curr.second + dc[i];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
        if (campus[nr][nc] != 'X' && !visited[nr][nc]) {
          q.push({nr, nc});
        }
      }
    }
  }

  if (ans > 0) cout << ans;
  else cout << "TT";
}

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
#define EMPTY 0
#define WALL 1
#define VIRUS 2

using namespace std;

int n, m;
int vmap[9][9];
bool visited[9][9] = {0};
int cVmap[9][9];
int ans = 0;
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0 ,1, -1 };

void spreadVirus(int r, int c) {
  if (visited[r][c]) return;
  if (vmap[r][c] == VIRUS) {
    visited[r][c] = true;
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
        if (vmap[nr][nc] == EMPTY) {
          vmap[nr][nc] = VIRUS;
          spreadVirus(nr, nc);
        }
      }
    }
  }
}

void copyVmap() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cVmap[i][j] = vmap[i][j];
    }
  }
}

void restoreVmap() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vmap[i][j] = cVmap[i][j];
      visited[i][j] = false;
    }
  }
}

void makeWall(int depth) {
  if (depth == 3) {
    copyVmap();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        spreadVirus(i, j);
      }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (vmap[i][j] == EMPTY) {
          cnt++;
        }
      }
    }

    ans = max(ans, cnt);

    restoreVmap();
    return;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vmap[i][j] == EMPTY) {
        vmap[i][j] = WALL;
        makeWall(depth+1);
        vmap[i][j] = EMPTY;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> vmap[i][j];
    }
  }

  // 벽 3개 세워야 함
  makeWall(0);

  cout << ans;
}

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

int r, c;
char alphabets[21][21];
bool visited[27];
int ans = 1;

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 } ;

void solve(int row, int col, int depth) {
  if (visited[alphabets[row][col] - 'A'] || ans == 26) return;

  ans = max(ans, depth);
  visited[alphabets[row][col] - 'A'] = true;

  for (int i = 0; i < 4; i++) {
    int nr = row + dr[i];
    int nc = col + dc[i];

    if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
      solve(nr, nc, depth + 1);
    }
  }

  visited[alphabets[row][col] - 'A'] = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> alphabets[i][j];
    }
  }

  solve(0, 0, 1);

  cout << ans;
}

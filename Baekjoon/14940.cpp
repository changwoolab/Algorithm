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

#define BLOCKED -2
#define INITIAL -3

using namespace std;

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  int arr[1001][1001] = {0};
  int visited[1001][1001] = {0};
  pair<int, int> target;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 0) arr[i][j] = BLOCKED;
      else if (arr[i][j] == 1) arr[i][j] = INITIAL;
      else if (arr[i][j] == 2) target = { i, j };
    }
  }

  queue<pair<int, pair<int, int> > > q;
  q.push({0, target});
  while (!q.empty()) {
    int phase = q.front().first;
    pair<int, int> coord = q.front().second;
    q.pop();

    int i = coord.first;
    int j = coord.second;

    if (arr[i][j] == BLOCKED) continue;

    if (!visited[i][j]) {
      visited[i][j] = 1;
      arr[i][j] = phase;

      for (int p = 0; p < 4; p++) {
        if (
          i + di[p] >= 0 &&
          i + di[p] < n &&
          j + dj[p] >= 0 &&
          j + dj[p] < m
        ) {
          q.push({phase + 1, {i + di[p], j + dj[p]}});
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == BLOCKED) {
        cout << 0 << ' ';
      } else if (arr[i][j] == INITIAL) {
        cout << -1 << ' ';
      } else {
        cout << arr[i][j] << ' ';
      }
    }
    cout << '\n';
  }
}

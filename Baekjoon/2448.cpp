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
int arr[4000][7000] = {0};

pair<pi, pi> getNext(int row, int col) {
  arr[row][col]++;
  arr[row+1][col-1]++;
  arr[row+1][col+1]++;
  for (int i = -2; i <= 2; i++) {
    arr[row+2][col+i]++;
  }
  
  return { {row+3, col-3}, {row+3, col+3} };
}

void solve(int row, int col) {
  // after, before
  queue<pair<pi, pi>> q;
  pair<pi, pi> next = getNext(row, col);
  q.push({next.first, {row, col}});
  q.push({next.second, {row, col}});

  while (!q.empty()) {
    pi current = q.front().first;
    pi before = q.front().second;
    q.pop();

    int row = current.first;
    int col = current.second;
    if (arr[before.first][before.second] % 2 == 0) continue;
    if (row < 0 || row >= n || col < 0 || col >= n*2-1) continue;

    pair<pi, pi> n = getNext(row, col);
    if (n.first.first == -1 && n.first.second == -1) continue;
    q.push({n.first, current});
    q.push({n.second, current});
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> n;
  solve(0, n-1);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n*2-1; j++) {
      if (arr[i][j] % 2 == 0) cout << ' ';
      else cout << '*';
    }
    cout << '\n';
  }
}

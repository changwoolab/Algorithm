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

const int NOT_DEFINED = 987654321;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m, x;
  cin >> n >> m >> x;

  int adj[1001][1001];

  for (int i = 0; i < 1001; i++) {
    for (int j = 0; j < 1001; j++) {
      if (i == j) continue;
      adj[i][j] = NOT_DEFINED;
    }
  }

  int s, e, t;
  for (int i = 0; i < m; i++) {
    cin >> s >> e >> t;
    adj[s][e] = t;
  }

  // 플로이드 와샬 알고리즘 실행
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }
  
  // 이제 제일 오래 걸리는 친구를 찾아보자
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i == x) continue;
    ans = max(ans, adj[i][x] + adj[x][i]);
  }
  cout << ans;
}

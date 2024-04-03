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

int n, m, r;
int T[101];
map<int, vector<pi>> locals;
bool visited[101] = {0};
int ans = 0;

void resetVisited() {
  for (int i = 0; i <= n; i++) {
    visited[i] = 0;
  }
}

// 노드 방문 순서에 따라 "더 먼 거리부터 탐색하면", 탐색 못하는 노드가 존재 가능하다
// 따라서 다익스트라 알고리즘을 통해 최소 거리에 있는 노드부터 탐색하여,
// 모든 방문 가능한 노드에 방문할 수 있도록 보장한다.
int djikstra(int current) {
  priority_queue<pi, vector<pi>, greater<pi>> q;
  q.push({0, current});

  int summ = 0;
  while (!q.empty()) {
    int cost = q.top().first;
    int node = q.top().second;
    q.pop();

    if (visited[node]) continue;

    summ += T[node];
    visited[node] = true;

    for (int i = 0; i < locals[node].size(); i++) {
      int nextCost = locals[node][i].first;
      int nextNode = locals[node][i].second;

      if (!visited[nextNode] && cost + nextCost <= m) {
        q.push({ cost + nextCost, nextNode });
      }
    }
  }

  return summ;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> n >> m >> r;
  for (int i = 1; i <= n; i++) {
    cin >> T[i];
  }
  for (int i = 0; i < r; i++) {
    int a, b, l;
    cin >> a >> b >> l;

    locals[a].push_back({l, b});
    locals[b].push_back({l, a});
  }

  for (int i = 1; i <= n; i++) {
    resetVisited();
    ans = max(ans, djikstra(i));
  }

  cout << ans;
}

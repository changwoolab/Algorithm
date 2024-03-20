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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  int s, e, c;
  map<int, vector<pi>> graph;
  for (int i = 0; i < m; i++) {
    cin >> s >> e >> c;
    graph[s].push_back({c, e});
  }

  priority_queue<pi, vector<pi>, greater<pi>> pq;
  int visited[1001] = {0};
  
  int a, b;
  cin >> a >> b;

  if (a == b) {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < graph[a].size(); i++) {
    pq.push(graph[a][i]);
  }

  int ans = 0;
  while (!pq.empty()) {
    int cost = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if (visited[node]) continue;
    if (node == b) {
      ans = cost;
      break;
    }
    visited[node] = 1;

    for (int i = 0; i < graph[node].size(); i++) {
      pq.push({ cost + graph[node][i].first, graph[node][i].second });
    }
  }

  cout << ans;
}

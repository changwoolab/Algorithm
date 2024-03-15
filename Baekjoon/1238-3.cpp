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
#define NOT_DEFINED 987654321

using namespace std;

typedef pair<int, int> pi; 

int n, m, x;
int s, e, t;
int cost1[1001] = {0};
int cost2[1001] = {0};
bool visited1[1001] = {0};
bool visited2[1001] = {0};
map<int, vector<pi>> graph;
map<int, vector<pi>> rgraph;

void solve(int *cost, bool *visited, map<int, vector<pi>> grp) {
  priority_queue <pi, vector<pi>, greater<pi>> pq;
  cost[x] = 0;
  pq.push({ 0, x });
  while(!pq.empty()) {
    int currentCost = pq.top().first;
    int currentNode = pq.top().second;
    pq.pop();

    if (visited[currentNode]) continue;
    visited[currentNode] = true;

    for (int i = 0; i < grp[currentNode].size(); i++) {
      pair<int, int> next = grp[currentNode][i];
      int nextCost = next.first;
      int nextNode = next.second;
      if (!visited[nextNode]) {
        cost[nextNode] = min(cost[nextNode], currentCost + nextCost);
        pq.push({ currentCost + nextCost, nextNode });
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  for (int i = 0; i < 1001; i++) cost1[i] = NOT_DEFINED;
  for (int i = 0; i < 1001; i++) cost2[i] = NOT_DEFINED;

  cin >> n >> m >> x;
  for (int i = 0; i < m; i++) {
    cin >> s >> e >> t;
    graph[s].push_back({ t, e });
    rgraph[e].push_back({ t, s });
  }

  solve(cost1, visited1, graph);
  solve(cost2, visited2, rgraph);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, cost1[i] + cost2[i]);
  }
  cout << ans;
}

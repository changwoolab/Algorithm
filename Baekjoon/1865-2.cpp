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
#define NOT_INITIALIZED 87654321

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  int tc;
  cin >> tc;

  int n, m, w;
  int s, e, t;
  while (tc--) {
    map<int, vector<pair<int,int>>> graph;
    cin >> n >> m >> w;
    for (int i = 0; i < m; i++) {
      cin >> s >> e >> t;
      graph[s].push_back({e, t});
      graph[e].push_back({s, t});
    }
    for (int i = 0; i < w; i++) {
      cin >> s >> e >> t;
      graph[s].push_back({e, -t});
    }

    int adj[501] = { 0 };
    for (int i = 0; i <= 501; i++) adj[i] = 0;

    bool isPossible = false;
    // i개의 간선을 지났을 때의 최소거리
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int k = 0; k < graph[j].size(); k++) {
          int end = graph[j][k].first;
          int cost = graph[j][k].second;

          if (i == n) {
            if (adj[end] != min(adj[end], adj[j] + cost)) {
              isPossible = true;
              break;
            }
          }
          adj[end] = min(adj[end], adj[j] + cost);
        }
      }
      if (isPossible) break;
    }

    if (isPossible) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
}

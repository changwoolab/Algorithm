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

  int tc;
  cin >> tc;

  int n, m, w;
  int s, e, t;
  while (tc--) {
    map<int, vector<pair<int, int> > > adj;
    cin >> n >> m >> w;
    for (int i = 0; i < m; i++) {
      cin >> s >> e >> t;
      // 음수가 가능한지만 알면 되므로 최솟값만 들어가면 된다.
      adj[s].push_back({e, t});
      adj[e].push_back({s, t});
    }
    for (int i = 0; i < w; i++) {
      cin >> s >> e >> t;
      adj[s].push_back({e, -t});
    }

    int dist[501] = {0};
    for (int i = 1; i <= n - 1; i++) {
      // 모든 간선을 확인한다
      // 우리는 정확한 최단거리를 파악하는게 목적이 아니라, 음의 사이클이 있는지만 파악하는 것이므로
      // 정점에 대해 이미 방문했는지 여부를 추적할 필요가 없다. 따라서 그냥 무지성으로 Min값 파악해주면 된다.
      for (int j = 1; j <= n; j++) {
        for (int k = 0; k < adj[j].size(); k++) {
          int endEdge = adj[j][k].first;
          int endCost = adj[j][k].second;
          dist[endEdge] = min(dist[endEdge], dist[j] + endCost);
        }
      }
    }

    // "n번째에도 업데이트 된다 = 음의 사이클이 존재한다" 로 파악 가능
    bool minusCycle = false;
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k < adj[j].size(); k++) {
        int endEdge = adj[j][k].first;
        int endCost = adj[j][k].second;
        int newMin = min(dist[endEdge], dist[j] + endCost);
        if (newMin != dist[endEdge]) {
          minusCycle = true;
          break;
        }
      }
      if (minusCycle) break;
    }

    if (minusCycle) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
}

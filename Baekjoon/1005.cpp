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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, k, w, time[1001] = {0}, indegree[1001] = {0}, result[1001] = {0};
    vector<int> adj[1001];
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> time[i];
    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      indegree[y]++;
    }
    cin >> w;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (indegree[i] == 0) q.push(i);
      result[i] = time[i];
    }

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      for (int i = 0; i < adj[node].size(); i++) {
        int nextNode = adj[node][i];
        indegree[nextNode]--;
        result[nextNode] = max(result[nextNode], result[node] + time[nextNode]);

        if (indegree[nextNode] == 0) q.push(nextNode);
      }
    }

    cout << result[w] << '\n';
  }
}

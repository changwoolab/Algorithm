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
#define NOT_INITIALIZED 987654321

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m, x;
  cin >> n >> m >> x;

  map<int, vector<pair<int, int>>> graph;
  map<int, vector<pair<int, int>>> reversedGraph;
  

  int s, e, t;
  for (int i = 0; i < m; i++) {
    cin >> s >> e >> t;
    graph[s].push_back({t, e});
    reversedGraph[e].push_back({t, s});
  }

  int d1[1001] = {0};
  int d2[1001] = {0};
  for (int i = 0; i < 1001; i++) d1[i] = NOT_INITIALIZED;
  for (int i = 0; i < 1001; i++) d2[i] = NOT_INITIALIZED;

  bool visited1[1001] = {0};
  bool visited2[1001] = {0};

  d1[x] = 0;
  d2[x] = 0;

 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q1;
  q1.push({0, x});
  while (!q1.empty()) {
    int distance = q1.top().first;
    int node = q1.top().second;
    q1.pop();
    if (visited1[node]) continue;
    visited1[node] = true;

    for (int i = 0; i < graph[node].size(); i++) {
      int nextNodeDistance = graph[node][i].first;
      int nextNode = graph[node][i].second;
      int newMin = min(d1[nextNode], distance + nextNodeDistance);
      if (newMin != d1[nextNode]) {
        d1[nextNode] = distance + nextNodeDistance;
        q1.push({distance + nextNodeDistance, nextNode});
      }
    }
  }

  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q2;
  q2.push({0, x});
  while (!q2.empty()) {
    int distance = q2.top().first;
    int node = q2.top().second;
    q2.pop();
    if (visited2[node]) continue;
    visited2[node] = true;

    for (int i = 0; i < reversedGraph[node].size(); i++) {
      int nextNodeDistance = reversedGraph[node][i].first;
      int nextNode = reversedGraph[node][i].second;
      int newMin = min(d2[nextNode], distance + nextNodeDistance);
      if (newMin != d2[nextNode]) {
        d2[nextNode] = distance + nextNodeDistance;
        q2.push({distance + nextNodeDistance, nextNode});
      }
    }
  }

  int maximum = 0;
  for (int i = 1; i <= n; i++) {
    if (i == x) continue;
    maximum = max(maximum, d1[i] + d2[i]);
  }

  cout << maximum;
}

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

using namespace std;

int n, k;
int visited[200001] = {0};

int solve() {
  priority_queue <pi, vector<pi>, greater<pi>> pq;
  pq.push({0, n});

  while(!pq.empty()) {
    int cost = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if (node == k) return cost;
    if (visited[node]) continue;
    visited[node] = 1;

    if (node+1 < 200000 && !visited[node+1]) pq.push({cost+1,node+1});
    if (node-1 >= 0 && !visited[node-1]) pq.push({cost+1,node-1});
    while(node != 0 && node*2 < 200000) {
      if (!visited[node*2]) pq.push({cost,node*2});
      node *= 2;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> n >> k;
  int ans = solve();
  cout << ans;
}

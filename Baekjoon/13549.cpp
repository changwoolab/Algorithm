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

int n, k;
int visited[200001] = {0};

int solve() {
  queue<pair<int, int>> q;
  q.push({n, 0});

  while (!q.empty()) {
    int node = q.front().first;
    int cost = q.front().second;
    q.pop();

    if (visited[node]) continue;
    visited[node] = 1;

    if (node == k) {
      return cost;
    }

    if (node+1 < 200000 && !visited[node+1]) q.push({node+1, cost+1});
    if (node-1 >= 0 && !visited[node-1]) q.push({node-1, cost+1});
    while (node != 0 && node*2 < 200000) {
      if (node*2 == k) return cost;
      if (!visited[node*2+1]) q.push({node*2+1, cost+1});
      if (!visited[node*2-1]) q.push({node*2-1, cost+1});
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

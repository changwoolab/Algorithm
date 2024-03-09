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
  int n, k, x, y, w;

  while (t--) {
    int indegree[1001] = { 0 };
    int minTimeToBuild[1001] = { 0 };
    int timeToBuild[1001] = { 0 };
    map<int, vector<int>> xy;
    queue<int> q;

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> timeToBuild[i];
    }
    for (int i = 0; i < k; i++) {
      cin >> x >> y;
      xy[x].push_back(y);
      indegree[y]++;
    }
    cin >> w;
    
    for (int i = 1; i <= n; i++) {
      if (indegree[i] == 0) {
        q.push(i);
        minTimeToBuild[i] = timeToBuild[i];
      }
    }

    while (!q.empty()) {
      int current = q.front();
      q.pop();

      for (int next : xy[current]) {
        minTimeToBuild[next] = 
          max(minTimeToBuild[next], minTimeToBuild[current] + timeToBuild[next]);
        indegree[next]--;
        if (indegree[next] == 0) q.push(next);
      }
    }

    cout << minTimeToBuild[w] << '\n';
  }
}

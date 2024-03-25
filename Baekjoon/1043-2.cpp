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

int parent[51];

int find(int node) {
  if (parent[node] == node) return node;

  parent[node] = find(parent[node]);
  return parent[node];
}

void unions(int node1, int node2) {
  int p1 = find(node1);
  int p2 = find(node2);

  parent[p2] = p1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  for (int i = 0; i < 51; i++) {
    parent[i] = i;
  }

  int n, m;
  cin >> n >> m;

  int knowCnt;
  cin >> knowCnt;

  int p = -1;
  for (int i = 0; i < knowCnt; i++) {
    int t;
    cin >> t;
    if (i == 0) p = t;
    else parent[t] = p;
  }

  map<int, vector<int>> party;
  for (int i = 0; i < m; i++) {
    int cnt;
    cin >> cnt;
    for (int j = 0; j < cnt; j++) {
      int t;
      cin >> t;
      party[i].push_back(t);
    }
  }

  for (int i = 0; i < m; i++) {
    for (int i = 0; i < m; i++) {
      bool someKnows = false;
      for (int j = 0; j < party[i].size(); j++) {
        if (find(party[i][j]) == p) {
          someKnows = true;
          break;
        }
      }

      if (someKnows) {
        for (int j = 0; j < party[i].size(); j++) {
          unions(p, party[i][j]);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < m; i++) {
    bool someKnows = false;
    for (int j = 0; j < party[i].size(); j++) {
      if (find(party[i][j]) == p) {
        someKnows = true;
        break;
      }
    }

    if (!someKnows) {
      ans++;
    }
  }

  cout << ans;
}

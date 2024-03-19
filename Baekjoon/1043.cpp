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

int n, m;
int knows;
int parent[51];
vector<vector<int>> parties;

int find(int node) {
  if (parent[node] == node) return node;

  parent[node] = find(parent[node]);
  return parent[node];
}

void unions(int node1, int node2) {
  int parent1 = find(node1);
  int parent2 = find(node2);

  parent[parent2] = parent1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  for (int i = 0; i < 51; i++) parent[i] = i;

  cin >> n >> m;

  cin >> knows;
  int root;
  for (int i = 0; i < knows; i++) {
    int p;
    cin >> p;
    if (i == 0) root = p;
    else unions(root, p);
  }

  int cnt, p;
  for (int i = 0; i < m; i++) {
    cin >> cnt;
    vector<int> partyPeople;
    while(cnt--) {
      cin >> p;
      partyPeople.push_back(p);
    }
    parties.push_back(partyPeople);
  }

  for (int k = 0; k < m; k++) {
    for (int i = 0; i < m; i++) {
      bool isKnow = false;
      for (int j = 0; j < parties[i].size(); j++) {
        int person = parties[i][j];
        if (find(person) == root) {
          isKnow = true;
          break;
        }
      }

      // 알고 있는 사람이 있다면 해당 파티의 사람들은 이제 다 알게 됨
      if (isKnow) {
        for (int j = 0; j < parties[i].size(); j++) {
          unions(root, parties[i][j]);
        }
      }
    }
  }

  // 이제 최대로 갈 수 있는 경우의 수를 찾아보자
  int ans = 0;
  for (int i = 0; i < m; i++) {
    bool isAble = true;
    for (int j = 0; j < parties[i].size(); j++) {
      int person = parties[i][j];
      if (find(person) == root) {
        isAble = false;
        break;
      }
    }
    if (isAble) {
      ans++;
    }
  }

  cout << ans;
}

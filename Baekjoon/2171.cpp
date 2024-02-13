#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <unordered_map>
#include <map>

using namespace std;

int main() {
  int N;
  cin >> N;

  map<pair<int, int>, bool> map;
  vector<pair<int, int> > vertex;

  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    vertex.push_back(make_pair(x, y));
    map[make_pair(x, y)] = true;
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (
        vertex[i].first != vertex[j].first &&
        vertex[i].second != vertex[j].second
      ) {
        if (
          map.count(make_pair(vertex[i].first, vertex[j].second)) &&
          map.count(make_pair(vertex[j].first, vertex[i].second))
        ) {
          ans++;
        }
      }
    }
  }

  cout << ans / 2;

  return 0;
}

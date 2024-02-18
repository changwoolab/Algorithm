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
  int n;
  cin >> n;

  vector<pair<int, int> > coord;
  map<pair<int, int>, bool> coordMap;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    coord.push_back(make_pair(x, y));
    coordMap[make_pair(x, y)] = true;
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    pair<int, int> p1 = coord[i];
    for (int j = i + 1; j < n; j++) {
      pair<int, int> p2 = coord[j];

      if (
        p1.first != p2.first &&
        p1.second != p2.second &&
        coordMap.count(make_pair(p1.first, p2.second)) &&
        coordMap.count(make_pair(p2.first, p1.second))
      ) {
        cnt++;
      }
    }
  }

  cout << (cnt / 2);
}

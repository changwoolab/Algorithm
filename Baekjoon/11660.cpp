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

  int n, m;
  cin >> n >> m;
  
  int arr[1025][1025] = { 0 };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[i][j];
      arr[i][j] += arr[i][j-1];
    }
  }

  while (m--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int cnt = 0;
    for (int i = x1; i <= x2; i++) {
      cnt += arr[i][y2] - arr[i][y1-1];
    }
    cout << cnt << '\n';
  }
}

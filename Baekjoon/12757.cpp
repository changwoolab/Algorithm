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

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M, K;
  cin >> N >> M >> K;

  map<int, int> m1;
  map<int, int> m2;
  for (int i = 0; i < N; i++) {
    int key, value;
    cin >> key >> value;
    m1[key] = value;
    m2[-key] = value;
  }

  for (int i = 0; i < M; i++) {
    int op, key, value;
    cin >> op >> key;
    if (op == 1) {
      cin >> value;
      m1[key] = value;
      m2[-key] = value;
      continue;
    }

    auto upper = m1.lower_bound(key); // plus
    auto lower = m2.lower_bound(-key); // minus
    int upperDiff = abs(upper->first - key);
    int lowerDiff = abs(key + lower->first);

    if (op == 2) {
      cin >> value;
      if (upperDiff < lowerDiff) {
        if (upperDiff <= K) {
          upper->second = value;
          m2[-(upper->first)] = value;
        }
      } else if (lowerDiff < upperDiff) {
        if (lowerDiff <= K) {
          lower->second = value;
          m1[-(lower->first)] = value;
        }
      }
    }
    
    if (op == 3) {
      if (upperDiff > K && lowerDiff > K) {
        cout << "-1" << '\n';
      } else if (upper->first != -lower->first && upperDiff == lowerDiff) {
        cout << "?" << '\n';
      } else if (upperDiff < lowerDiff) {
        cout << upper->second << '\n';
      } else {
        cout << lower->second << '\n';
      }
    }
  }
}

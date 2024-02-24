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

const int NOT_FOUND = -1;
const int DUPLICATED = -2;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;

  map<int, int> kv;
  map<int, int> mkv;

  for (int i = 0; i < n; i++) {
    int key, value;
    cin >> key >> value;
    kv[key] = value;
    mkv[-key] = value;
  }

  for (int i = 0; i < m; i++) {
    int op, key, value;
    cin >> op >> key;
    if (op != 3) {
      cin >> value;
    } 

    // find key
    int upper = kv.lower_bound(key)->first; // 자기보다 큰거
    int lower = -mkv.lower_bound(-key)->first; // 자기보다 작은거
    int upperDiff = abs(upper - key);
    int lowerDiff = abs(lower - key);

    int targetKey;
    if (upperDiff > k && lowerDiff > k) {
      targetKey = NOT_FOUND;
    } else if (lowerDiff == upperDiff && upper != lower) {
      targetKey = DUPLICATED;
    } else if (upper == lower) {
      targetKey = key;
    } else if (lowerDiff < upperDiff) {
      targetKey = lower;
    } else if (lowerDiff > upperDiff) {
      targetKey = upper;
    } else {
      targetKey = NOT_FOUND;
    }

    if (op == 1) {
      kv[key] = value;
      mkv[-key] = value;
    } else if (op == 2) { // 변경
      if (targetKey != NOT_FOUND && targetKey != DUPLICATED) {
        kv[targetKey] = value;
        mkv[-targetKey] = value;
      }
    } else { // 출력
      if (targetKey == NOT_FOUND) {
        cout << "-1" << '\n';
      } else if (targetKey == DUPLICATED) {
        cout << '?' << '\n';
      } else {
        cout << kv[targetKey] << '\n';
      }
    }
  }
}

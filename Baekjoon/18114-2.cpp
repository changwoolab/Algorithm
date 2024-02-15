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
  int N, C;
  cin >> N >> C;
  
  vector<int> w;
  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    w.push_back(t);
  }

  sort(w.begin(), w.end());

  bool isAble = false;
  for (int i = 0; i < N; i++) {
    if (w[i] == C || isAble) {
      isAble = true;
      break;
    }
    
    int l = i+1, r = N-1;
    while (l < r) {
      long long weight = w[i] + w[l] + w[r];

      if (
        w[l] == C ||
        w[r] == C ||
        weight - w[i] == C ||
        weight - w[r] == C ||
        weight - w[l] == C ||
        weight == C
      ) {
        isAble = true;
        break;
      }

      if (weight > C) r--;
      else l++;
    }
  }

  cout << (isAble ? 1 : 0);
}

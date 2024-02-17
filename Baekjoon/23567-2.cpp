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
  int n, k;
  cin >> n >> k;

  vector<int> p;
  map<int, int> P;
  for (int i = 0; i < n; i++) {
    int _p;
    cin >> _p;
    p.push_back(_p);
    P[_p]++;
  }

  int ans = 99999;
  map<int, int> PC;
  int left = 0, right = 0;
  while (left <= right && right < n) {
    if (P.size() == k && PC.size() == k) ans = min(ans, right-left);

    if (PC.size() < k) {
      PC[p[right]]++;
      P[p[right]]--;
      if (P[p[right]] == 0) P.erase(p[right]);
      right++;
    } else {
      PC[p[left]]--;
      P[p[left]]++;
      if (PC[p[left]] == 0) PC.erase(p[left]);
      left++;
    }
  }

  cout << (ans == 99999 ? 0 : ans);
}

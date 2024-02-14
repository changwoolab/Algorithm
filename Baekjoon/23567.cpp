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

  vector<int> colors;
  unordered_map<int, int> primeColors;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    colors.push_back(c);
    primeColors[c]++;
  }

  int ans = 10001;
  unordered_map<int, int> pPrimeColors;
  int slow = 0, fast = 0;
  while (fast < n && slow <= fast) {
    if (primeColors.size() == k && pPrimeColors.size() == k) {
      ans = std::min(ans, fast - slow);
    }

    if (pPrimeColors.size() == k) {
      pPrimeColors[colors[slow]]--;
      primeColors[colors[slow]]++;
      if (!pPrimeColors[colors[slow]]) pPrimeColors.erase(colors[slow]);
      slow++;
    } else {
      pPrimeColors[colors[fast]]++;
      primeColors[colors[fast]]--;
      if (!primeColors[colors[fast]]) primeColors.erase(colors[fast]);
      fast++;
    }
  }

  cout << ((ans == 10001) ? 0 : ans);
  return 0;
}

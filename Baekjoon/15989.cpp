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

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    int dp[10001] = { 1 };
    for (int i = 1; i <= n; i++) dp[i] = 1;
    for (int i = 2; i <= n; i++) dp[i] += dp[i-2];
    for (int i = 3; i <= n; i++) dp[i] += dp[i-3];

    cout << dp[n] << '\n';
  }
}

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

  int n;
  cin >> n;

  int dp[1001] = { 0, 1, 3 };
  for (int i = 3; i <= n; i++) {
    dp[i] = (dp[i-1] + 2 * dp[i-2]) % 10007;
  }

  cout << dp[n] % 10007;
}

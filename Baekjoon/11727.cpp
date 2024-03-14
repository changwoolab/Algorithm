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
#define MOD 10007

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  int n;
  cin >> n;

  int dp[1001] = {0};
  dp[1] = 1;
  dp[2] = 3;

  for (int i = 3; i <= n; i++) {
    dp[i] = (dp[i-1] + dp[i-2] * 2) % MOD;
  }

  cout << (dp[n] % MOD);
}

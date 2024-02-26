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

const int MOD = 10000003;

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  int n;
  cin >> n;

  vector<int> s;
  int dp[51][100001];
  for (int i = 0; i < n; i++) {
    int _s;
    cin >> _s;
    s.push_back(_s);
    dp[i][_s] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < 100001; j++) {
      dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;

      int cop = gcd(s[i], j);
      dp[i][cop] = (dp[i][cop] + dp[i-1][j]) % MOD;
    }
  }

  cout << dp[n-1][1];
}

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

const int MOD = pow(10, 9) + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> A;
  vector<int> B;

  int visitedCnt = 0;
  vector<bool> visited(7, false);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    A.push_back(a);
    if (!visited[a % 7]) {
      visitedCnt++;
      visited[a % 7] = true;
    }
  }
  for (int i = 0; i < m; i++) {
    int b;
    cin >> b;
    B.push_back(b);
  }

  int _sum = 0;
  int targetSum = 0;
  // 현재 Bi에 더해서 나머지가 7이 되는 친구를 visited 처리한다.
  for (int i = 0; i < m; i++) {
    int target = (B[i] + targetSum) % 7 == 0 ? 0 : 7 - (B[i] + targetSum) % 7;

    if (visited[target]) {
      if (visitedCnt == 1) {
        continue;
      }
      visitedCnt--;
      visited[target] = false;
    }

    targetSum = (targetSum + B[i]) % 7;
    _sum = (_sum + B[i]) % MOD;
  }

  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (visited[A[i] % 7]) ans.push_back(A[i]);
  }

  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ((ans[i] + _sum) % MOD) << ' ';
  }
}

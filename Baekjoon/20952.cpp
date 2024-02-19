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

int M = pow(10, 9) + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> A;
  vector<bool> visited(7, false);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    A.push_back(a);
    if (!visited[a % 7]) {
      visited[a % 7] = true;
      cnt++;
    }
  }

  vector<int> B;
  for (int i = 0; i < m; i++) {
    int b;
    cin >> b;
    B.push_back(b);
  }

  int _sum = 0, check = 0;
  for (int i = 0; i < m; i++) {
    int temp = ((check + B[i]) % 7 != 0) ? 7 - (check + B[i]) % 7 : 0;
    if (visited[temp]) {
      if (cnt == 1) continue;
      visited[temp] = false;
      cnt--;
    }

    check = (check + B[i]) % 7;
    _sum += B[i];
    _sum %= M;
  }

  vector<int> result;
  for (int i = 0; i < n; i++) {
    if (visited[A[i] % 7]) {
      result.push_back((A[i] + _sum) % M);
    }
  }
  cout << result.size() << '\n';
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << ' ';
  }
}

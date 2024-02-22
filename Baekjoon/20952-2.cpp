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

const int M = pow(10, 9) + 7;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> A;
  vector<int> B;

  // True라면, 해당 나머지로 시작한 애들이 아무리 연산해도 7의 배수가 아닌 친구들이 된다는 뜻
  vector<bool> remainder(7, false);

  // 몇개의 7의 배수가 아닌 친구들이 남았는가
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    A.push_back(a);
    if (remainder[a % 7] == false) {
      remainder[a % 7] = true;
      cnt++;
    }
  }
  for (int i = 0; i < m; i++) {
    int b;
    cin >> b;
    B.push_back(b);
  }

  int summ = 0;
  int forCheck = 0;
  for (int i = 0; i < m; i++) {
    // 더해서 7의 배수가 되는 수를 찾는다
    int temp = ((forCheck + B[i]) % 7 != 0) ? 7 - ((forCheck + B[i]) % 7) : 0;

    // 7의 배수가 안 된다면
    if (remainder[temp] == true) {
      if (cnt == 1) continue; // 만약 연산을 진행했을 때 모두 없어진다면 연산 수행 X
      remainder[temp] = false;
      cnt--;
    }

    summ = (summ + B[i]) % M;
    forCheck = (forCheck + B[i]) % 7;
  }

  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (remainder[A[i] % 7]) {
      ans.push_back((A[i] + summ) % M);
    }
  }

  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << ' ';
  }
}

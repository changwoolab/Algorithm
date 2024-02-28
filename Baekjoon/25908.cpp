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

  int s, t;
  cin >> s >> t;

  int ans = 0;
  for (int i = 1; i <= t; i++) {
    // s ~ t까지의 i번째 원소의 개수
    // s ~ t 사이의 i의 배수의 개수를 구할 수 있으면 됨..
    // 그럼 cnt는 t까지의 i의 배수의 개수 - s까지의 i배수의 개수 아님?
    int cnt = 0;
    cnt = (t / i) - (s / i) + (s % i == 0 ? 1 : 0);

    if (i % 2 == 0) {
      ans += cnt;
    } else {
      ans += (-cnt);
    }
  }

  cout << ans;
}

// a1 = -1
// a2 = -1  + 1
// a3 = -1  + 0 + -1
// a4 = -1  + 1 +  0  +  1
// a5 = -1  + 0 +  0  +  0  + -1
// a6 = -1  + 1 + -1  +  0  +  0  +  1
// a7 = -1  + 0 +  0  +  0  +  0  +  0  +  1
// a8 = -1  + 1 +  0  +  1  +  0  +  0  +  0  +  1

// 1번째 원소는 계속 -1이 나오고
// 2번째 원소는 2번째부터 2번마다 1이 나오고
// 3번째 원소는 3번째부터 3번마다 -1이 나오고
// 4번째 원소는 4번째부터 4번마다 1이 나오고
// ...

// 결국 1의 개수와 -1의 개수를 알면 되는데,
// 이 개수는 원소의 위치로부터 결정됨

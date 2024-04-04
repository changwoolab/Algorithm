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
#define pi pair<int, int>
#define NOT_DEFINED 987654321

using namespace std;

int x;
int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> x;

  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    x -= a * b;
  }

  if (x == 0) cout << "Yes";
  else cout << "No";
}

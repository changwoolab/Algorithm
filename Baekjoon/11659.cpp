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

  int n, m;
  cin >> n >> m;

  int nums[400001] = { 0 };
  for (int i = 1; i <= n; i++) {
    cin >> nums[i];
    nums[i] += nums[i-1];
  }

  for (int i = 0; i < m; i++) {
    int s, e;
    cin >> s >> e;
    cout << nums[e] - nums[s - 1] << '\n';
  }
}

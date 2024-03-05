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

int n, m;
int nums[10001];
bool visited[10001];
vector<int> current;
map<string, bool> printed;

void solve(int depth) {
  if (depth == 0) {
    string toPrint = "";
    for (int i = 0; i < current.size(); i++) {
      toPrint += nums[current[i]];
    }
    if (!printed.count(toPrint)) {
      for (int i = 0; i < current.size(); i++) {
        cout << nums[current[i]] << ' ';
      }
      cout << '\n';
    }
    printed[toPrint] = true;
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      current.push_back(i);
      visited[i] = true;
      solve(depth-1);
      visited[i] = false;
      current.pop_back();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> nums[i];
  sort(nums, nums + n);

  solve(m);
}

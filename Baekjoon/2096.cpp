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

int n;
int nums[100001][3];
int maximums[3] = { 0, 0, 0 };
int minimums[3] = { NOT_DEFINED, NOT_DEFINED, NOT_DEFINED };
int dc[3] = { -1, 0, 1 };

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> n;
  int t1, t2, t3;
  for (int i = 0; i < n; i++) {
    cin >> nums[i][0];
    cin >> nums[i][1];
    cin >> nums[i][2];
  }

  maximums[0] = minimums[0] = nums[0][0];
  maximums[1] = minimums[1] = nums[0][1];
  maximums[2] = minimums[2] = nums[0][2];

  for (int r = 0; r < n - 1; r++) {
    int nextMax[3] = { 0, 0, 0 };
    int nextMin[3] = { NOT_DEFINED, NOT_DEFINED, NOT_DEFINED };
    int nr = r + 1;
    for (int c = 0; c < 3; c++) {
      // (1, -1) (1, 0) (1, 1) 방향으로 갈 수 있음
      for (int i = 0; i < 3; i++) {
        int nc = c + dc[i];
        if (nc >= 0 && nc < 3) {
          nextMax[nc] = max(nextMax[nc], maximums[c] + nums[nr][nc]);
          nextMin[nc] = min(nextMin[nc], minimums[c] + nums[nr][nc]);
        }
      }
    }

    for (int i = 0; i < 3; i++) {
      maximums[i] = nextMax[i];
      minimums[i] = nextMin[i];
    }
  }

  int maxi = 0, mini = NOT_DEFINED;
  for (int i = 0; i < 3; i++) {
    maxi = max(maxi, maximums[i]);
    mini = min(mini, minimums[i]);
  }

  cout << maxi << ' ' << mini;
}

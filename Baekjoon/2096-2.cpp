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
int d[3] = { -1, 0, 1 };

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> nums[i][j];
    }
  }

  int mini[3] = {nums[0][0], nums[0][1], nums[0][2]};
  int maxi[3] = {nums[0][0], nums[0][1], nums[0][2]};
  int tempMini[3] = {0};
  int tempMaxi[3] = {0};
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < 3; j++) {
      tempMini[j] = mini[j];
      tempMaxi[j] = maxi[j];

      // 일단 같은 column에 있는 값을 넣어줘서 min, max를 비교할 수 있도록 하기
      mini[j] = mini[j] + nums[i+1][j];
      maxi[j] = maxi[j] + nums[i+1][j];
    }

    // temp 값을 돌면서 다음 layer 값들을 모두 넣어본다
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        int nextCol = j + d[k];
        if (nextCol >= 0 && nextCol < 3) {
          mini[nextCol] = min(mini[nextCol], tempMini[j] + nums[i+1][nextCol]);
          maxi[nextCol] = max(maxi[nextCol], tempMaxi[j] + nums[i+1][nextCol]);
        }
      }
    }
  }

  int ansMax = 0;
  int ansMin = NOT_DEFINED;
  for (int i = 0; i < 3; i++) {
    ansMax = max(ansMax, maxi[i]);
    ansMin = min(ansMin, mini[i]);
  }

  cout << ansMax << ' ' << ansMin;
}

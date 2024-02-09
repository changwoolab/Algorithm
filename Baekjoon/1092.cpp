#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> weightLimits;
  for (int i = 0; i < N; i++) {
    int w;
    cin >> w;
    weightLimits.push_back(w);
  }

  int M;
  cin >> M;

  vector<int> boxWeights;
  for (int i = 0; i < M; i++) {
    int w;
    cin >> w;
    boxWeights.push_back(w);
  }

  sort(weightLimits.begin(), weightLimits.end());
  sort(boxWeights.begin(), boxWeights.end());

  // max(boxWeights) > max(weightLimits) 이면 옮기기 불가능
  if (boxWeights[M-1] > weightLimits[N-1]) {
    cout << -1;
    return 0;
  }

  // 들 수 있는 가장 무거운것부터 하나하나 옮긴다
  int minutes = 0;
  while (boxWeights.size() > 0) {
    int container = N-1;
    for (int i = boxWeights.size() - 1; i >= 0; i--) {
      if (container == -1) break;
      // cout << container << '\n';
      if (weightLimits[container] >= boxWeights[i]) {
        boxWeights.erase(boxWeights.begin() + i);
        container--;
      }
    }
    minutes++;
  }

  cout << minutes;
}

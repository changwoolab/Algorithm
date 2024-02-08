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

  vector<int> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  int S;
  cin >> S;

  int index = 0;
  int cnt = 0;
  bool changed = true;
  while (cnt < S && changed && index < N) {
    changed = false;
    // 제일 큰 값이 S - cnt번 이내에 swap 될 수 있으면, Swap 해준다.
    // swap 불가능하다면 그 다음 큰 숫자를 찾아서 S - cnt번 이내에 swap 될 수 있는지 검사
    unordered_map<int, int> maxIdxs;
    int distance = N;
    int max = 0;
    int maxIdx = index;
    int ttt = 0;
    do {
      if (maxIdx != index) maxIdxs[maxIdx] = maxIdx;

      max = 0;
      maxIdx = index;
      for (int i = index; i < N; i++) {
        // 이미 swap 불가능하다고 판단된 max값이면 반영 X
        if (max < A[i] && !maxIdxs.count(i)) {
          maxIdx = i;
          max = A[i];
        }
      }

      distance = maxIdx - index;
    } while (distance > S - cnt);

    for (int i = maxIdx; i > index; i--) {
      int temp = A[i-1];
      A[i-1] = A[i];
      A[i] = temp;
    }

    index++;
    changed = true;
    cnt += distance;
  }

  for(int i = 0; i < N; i++) {
    cout << A[i] << ' ';
  }
}

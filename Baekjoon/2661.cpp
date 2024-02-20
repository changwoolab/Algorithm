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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  cin >> N;

  string seq = "1";
  bool beforeIsNotAbleToProceed = false;
  // 길이가 N이 될때까지 반복
  while (seq.size() < N) {
    char c = '1';
    if (beforeIsNotAbleToProceed) {
      c = seq[seq.size() - 1] + 1;
      seq.erase(seq.begin() + seq.size() - 1);
    }
    beforeIsNotAbleToProceed = false;
    // 1 ~ 3까지 작은 순서대로 차례대로 넣어줌
    for (; c <= '3'; c++) {
      string tempSeq = seq + c;
      bool isAble = true;
      // 길이을 늘려가며 인접한 동일한게 있는지 검사
      for (int length = 1; length < tempSeq.size(); length++) {
        int right = tempSeq.size() - 1;
        int left = tempSeq.size() - 1 - length;
        int cnt = 0;
        int tempLen = 0;
        while (cnt < length && left >= 0) {
          if (tempSeq[left] == tempSeq[right]) {
            tempLen++;
          }
          cnt++;
          right--;
          left--;
        }
        // 동일한게 존재
        if (tempLen == length) {
          if (c == '3') beforeIsNotAbleToProceed = true;
          isAble = false;
        }
      }
      if (isAble) {
        seq = tempSeq;
        break;
      }
    }
  }

  std::cout << seq;
}

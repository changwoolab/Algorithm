#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_map>

using namespace std;

bool hasIt(vector<int> w, int remaining, int left, int right) {
  int mid = (right + left) / 2;
  while (left < right) {
    mid = (right + left) / 2;
    if (w[mid] > remaining) right = mid - 1;
    else if (w[mid] == remaining) break;
    else left = mid + 1;
  }

  return w[mid] == remaining;
}

int main() {
  int N, C;
  cin >> N >> C;

  vector<int> w;
  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    w.push_back(t);
  }

  sort(w.begin(), w.end());
  
  int isAble = false;

  for (int i = 0; i < N; i++) {
    int left = i+1, right = N-1;

    while (left < right) {
      long long sum = w[i] + w[left] + w[right];

      if (
        sum == C ||
        w[i] == C ||
        w[left] == C ||
        w[right] == C ||
        sum - w[left] == C ||
        sum - w[right] == C ||
        sum - w[i] == C
      ) {
        isAble = true;
        break;
      }

      if (sum > C) {
        right--;
      } else {
        left++;
      }
    }
  }

  if (isAble) {
    cout << 1;
  } else {
    cout << 0;
  }

  return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<string> decreasing;

void calculateAllDecreasing(int depth, string curr) {
  if (depth == 0) {
    decreasing.push_back(curr);
    return;
  }

  for (int i = 0; i <= 9; i++) {
    if (curr.size() > 0 && i >= curr[curr.size() - 1] - '0') {
      continue;
    }
    calculateAllDecreasing(depth - 1, curr + to_string(i));
  }
}

int main() {
  int N;
  cin >> N;

  int count = 0;
  for (int depth = 1; depth <= 10; depth++) {
    for (int i = 0; i <= 9; i++) {
      calculateAllDecreasing(depth - 1, to_string(i));
    }
  }

  if (N < decreasing.size()) {
    cout << decreasing[N];
  } else {
    cout << -1;
  }

  return 0;
}

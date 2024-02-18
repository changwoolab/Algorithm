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
  int n, c;
  cin >> n >> c;

  vector<int> w;
  for (int i = 0; i < n; i++) {
    int _w;
    cin >> _w;
    w.push_back(_w);
  }

  sort(w.begin(), w.end());

  bool isAble = false;
  for (int i = 0; i < n; i++) {
    int weight = w[i];

    int left = i+1, right = n-1;
    while (left < right) {
      long long summ = weight + w[left] + w[right];
      if (
        weight == c ||
        w[left] == c ||
        w[right] == c ||
        weight + w[left] == c ||
        weight + w[right] == c ||
        summ == c
      ) {
        isAble = true;
        break;
      }

      if (summ > c) {
        right--;
      } else {
        left++;
      }
    }

    if (isAble) break;
  }

  cout << isAble;
}

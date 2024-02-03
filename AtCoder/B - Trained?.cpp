#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> a;
  for (int i = 0; i < N; i++) {
    int aa;
    cin >> aa;
    a.push_back(aa - 1);
  }

  vector<int> visited(N);

  int currIndex = 0;
  int cnt = 0;
  while (currIndex != 1) {
    cnt++;
    visited[currIndex] = 1;
    currIndex = a[currIndex];

    if (visited[currIndex] == 1) {
      cnt = -1;
      break;
    }
  }

  cout << cnt;

  return 0;
}

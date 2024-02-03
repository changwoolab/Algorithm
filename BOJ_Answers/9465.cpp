#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solve(int n, vector<vector<int> > vec) {
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < 2; i++) {
      int curr = vec[i][j];
      if (i == 0) {
        if (j - 1 >= 0) vec[i][j] = max(vec[i][j] + vec[1][j-1], vec[i][j-1]);
      } else {
        if (j - 1 >= 0) vec[i][j] = max(vec[i][j] + vec[0][j-1], vec[i][j-1]);
      }
    }
  }

  return max(vec[0][n-1], vec[1][n-1]);
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int n;
    cin >> n;
    vector<vector<int> > vec(2, vector<int> (n, 0));
    for (int j = 0; j < n; j++) {
      int k;
      cin >> k;
      vec[0][j] = k;
    }
    for (int j = 0; j < n; j++) {
      int k;
      cin >> k;
      vec[1][j] = k;
    }

    int result = solve(n, vec);
    if (i == T-1) {
      cout << result;
    } else {
      cout << result << endl;
    }
  }
}

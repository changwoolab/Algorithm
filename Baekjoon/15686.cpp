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
#define EMPTY 0
#define HOUSE 1
#define CHICKEN 2

using namespace std;

int n, m;
int city[51][51];
vector<pi> chickens;
bool visited[51][51] = {0};
int mini = NOT_DEFINED;
vector<pi> sel;

void select(int lastIdx) {
  if (sel.size() == m) {
    int candidate = 0;

    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (city[j][k] == HOUSE) {
          int small = NOT_DEFINED;
          for (int i = 0; i < sel.size(); i++) {
              int r = sel[i].first;
              int c = sel[i].second;
              small = min(small, (abs(j-r) + abs(k-c)));
          }
          candidate += small;
        }
      }
    }

    mini = min(mini, candidate);
    return;
  }

  for (int i = lastIdx; i < chickens.size(); i++) {
    int row = chickens[i].first;
    int col = chickens[i].second;

    if (!visited[row][col]) {
      visited[row][col] = true;
      sel.push_back({row, col});
      select(i+1);
      sel.pop_back();
      visited[row][col] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> city[i][j];
      if (city[i][j] == CHICKEN) chickens.push_back({i, j});
    }
  }

  select(0);

  cout << mini;
}

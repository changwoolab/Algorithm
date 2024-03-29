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

int n, k;
int dp[200001] = {0};
int visited[200001] = {0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  cin >> n >> k;

  queue<int> q;
  q.push(n);
  visited[n] = 1;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    if (curr == k) {
      break;
    }

    // 단 한번도 방문한 적이 없거나, 비용이 동일할 때에만 queue에 넣어줌
    if (curr - 1 >= 0) {
      if (dp[curr-1] == 0) {
        q.push(curr-1);
        dp[curr-1] = dp[curr] + 1;
        visited[curr-1] = visited[curr];
      } else if (dp[curr-1] == dp[curr]+1) {
        visited[curr-1] += visited[curr];
      }
    }

    if (curr + 1 <= 200000) {
      if (dp[curr+1] == 0) {
        q.push(curr+1);
        dp[curr+1] = dp[curr] + 1;
        visited[curr+1] = visited[curr];
      } else if (dp[curr+1] == dp[curr]+1) {
        visited[curr+1] += visited[curr];
      }
    }

    if (curr > 0 && curr * 2 <= 200000 && (dp[curr*2] == 0 || dp[curr*2] == dp[curr]+1)) {
      if (dp[curr*2] == 0) {
        q.push(curr*2);
        dp[curr*2] = dp[curr] + 1;
        visited[curr*2] = visited[curr];
      } else if (dp[curr*2] == dp[curr]+1) {
        visited[curr*2] += visited[curr];
      }
    }
  }

  cout << dp[k] << '\n';
  cout << visited[k];
}

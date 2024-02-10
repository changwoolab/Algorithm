#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
  int C, N;
  cin >> C >> N;

  vector<vector<int> > customerCost(N);
  for (int i = 0; i < N; i++) {
    int cost, customer;
    cin >> cost >> customer;
    customerCost[i].push_back(customer);
    customerCost[i].push_back(cost);
  }

  // dp[i] = i명을 가져오는데 드는 최소 비용
  vector<int> dp;
  dp.push_back(0);
  for (int i = 1; i <= C + 100; i++) {
    int minimumCost = 100001;

    for (int j = 0; j < customerCost.size(); j++) {
      int customers = customerCost[j][0];
      int cost = customerCost[j][1];

      if (i - customers >= 0) {
        minimumCost = std::min(minimumCost, cost + dp[i-customers]);
      } else {
        minimumCost = std::min(minimumCost, cost);
      }
    }

    dp.push_back(minimumCost);
  }

  int minimum = 100001;
  for (int i = 0; i <= 100; i++) {
    minimum = std::min(minimum, dp[C+i]);
  }

  std::cout << minimum;
}

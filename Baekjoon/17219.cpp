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

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  map<string, string> mp;

  for (int i = 0; i < n; i++) {
    string link, pw;
    cin >> link >> pw;
    mp[link] = pw;
  }

  for (int i = 0; i < m; i++) {
    string link;
    cin >> link;
    cout << mp[link] << '\n';
  }
}

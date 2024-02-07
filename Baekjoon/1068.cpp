#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
  int N;
  cin >> N;

  int root = 0;
  unordered_map<int, vector<int> > graph;
  for (int node = 0; node < N; node++) {
    int parent;
    cin >> parent;
    if (parent == -1) root = node;
    else graph[parent].push_back(node);
  }

  int toDelete;
  cin >> toDelete;

  int leafNodeCnt = 0;
  queue<int> q;
  q.push(root);
  while (q.size() > 0) {
    int node = q.front();
    q.pop();

    if (node == toDelete) continue;
    if (!graph.count(node)) leafNodeCnt++;

    int childrenCnt = 0;
    bool isChildTruncated = false;
    for (int child : graph[node]) {
      if (child == toDelete) isChildTruncated = true;
      else q.push(child);
      childrenCnt++;
    }

    if (childrenCnt == 1 && isChildTruncated) leafNodeCnt++;
  }

  cout << leafNodeCnt;
}

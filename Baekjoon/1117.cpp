#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
  long long W, H, f, c, x1, y1, x2, y2;
  cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;

  long long originalArea = W * H;

  // 기준점
  long long datum = (f <= W/2) ? f : W - f;

  long long newArea1 = 0;
  long long newArea2 = 0;
  long long newHeight = y2 - y1;

  if (x1 < datum && datum < x2) {
    newArea1 = (datum - x1) * newHeight * 2 * (c+1);
    newArea2 = (x2 - datum) * newHeight * (c+1);
  } else if (x1 < x2 && x2 <= datum) {
    newArea1 = (x2 - x1) * newHeight * 2 * (c+1);
  } else {
    newArea2 = (x2 - x1) * newHeight * (c+1);
  }

  cout << originalArea - newArea1 - newArea2;
}

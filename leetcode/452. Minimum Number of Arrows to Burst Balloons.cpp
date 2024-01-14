// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/solutions/4563300/c-solution-using-sorting/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int ans = 1;
        int currentOverlappingZone = points[0][1];

        for (auto point : points) {
            if (currentOverlappingZone >= point[0]) {
                currentOverlappingZone = min(currentOverlappingZone, point[1]);
            } else {
                ans++;
                currentOverlappingZone = point[1];
            }
        }

        return ans;
    }
};

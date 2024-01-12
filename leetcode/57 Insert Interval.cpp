// https://leetcode.com/problems/insert-interval/solutions/4551661/c-easy-solution/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int size = intervals.size();
        vector<vector<int>> ans;

        int i = 0;
        
        // Insert intervals while it is smaller than the newInterval[0]
        while(i < size && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

		// Merge the overlappings
        while(i < size && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        ans.push_back(newInterval);
        
        // Insert non-overlapping intervals
        while(i < size){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};

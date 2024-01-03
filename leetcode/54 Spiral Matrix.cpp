// https://leetcode.com/problems/spiral-matrix/solutions/4499455/c-solution-with-dfs/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        visitDfs(matrix, ans, 0, 0, 0);
        return ans;
    }

private:
    int VISITED = 101;
    
    vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int visitDfs(vector<vector<int>>& matrix, vector<int>& ans, int i, int j, int mode) {
        if (mode == VISITED) return VISITED;
        if (i < 0 || i >= matrix.size()) return changeMode(mode);
        if (j < 0 || j >= matrix[0].size()) return changeMode(mode);
        if (matrix[i][j] == VISITED) return changeMode(mode);

        ans.push_back(matrix[i][j]);
        matrix[i][j] = VISITED;

        for (int p = 0; p < 4; p++) {
            int di = d[mode].first;
            int dj = d[mode].second;
            mode = visitDfs(matrix, ans, i+di, j+dj, mode);
            if (mode == VISITED) return VISITED;
        }

        return VISITED;
    }

    int changeMode(int mode) {
        return (++mode) % 4;
    }
};

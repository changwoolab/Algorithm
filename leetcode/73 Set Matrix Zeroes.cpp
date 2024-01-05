// https://leetcode.com/problems/set-matrix-zeroes/solutions/4511239/c-solution-with-o-1-space/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        bool flag1 = false, flag2 = false;

        for (int i = 0; i < rowSize; i++) {
            if (matrix[i][0] == 0) flag1 = true;
        }

        for (int j = 0; j < colSize; j++) {
            if (matrix[0][j] == 0) flag2 = true;
        }

        for (int i = 1; i < rowSize; i++) {
            for (int j = 1; j < colSize; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < rowSize; i++) {
            for (int j = 1; j < colSize; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }

        if (flag1) {
            for (int k = 0; k < rowSize; k++) matrix[k][0] = 0;
        }

        if (flag2) {
            for (int k = 0; k < colSize; k++) matrix[0][k] = 0;
        }
    }
};

// https://leetcode.com/problems/rotate-image/solutions/4506209/c-very-naive-solution/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for(int i = 0; i < (matrix.size()+1) / 2; i++) {    
            // rotation times = length of row - 1
            int rotationTime = size - 1;
            for (int j = 0; j < rotationTime; j++) {
                rotateOnce(matrix, i, size);
            }

            // length of row becomes -2 as i goes
            size -= 2;
        }
    }

private:
    void rotateOnce(vector<vector<int>>& matrix, int startIndex, int size) {
        int i = startIndex;
        int j = startIndex;
        int prev = matrix[i][j];

        // rotate upward row
        for (; j < startIndex + size; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = prev;
            prev = temp;
        }
        j--;

        // rotate the right column
        for (++i; i < startIndex + size; i++) {
            int temp = matrix[i][j];
            matrix[i][j] = prev;
            prev = temp;
        }
        i--;

        // rotate the downward row
        for (--j; j >= startIndex; j--) {
            int temp = matrix[i][j];
            matrix[i][j] = prev;
            prev = temp;
        }
        j++;

        // rotate the left column
        for (--i; i >= startIndex; i--) {
            int temp = matrix[i][j];
            matrix[i][j] = prev;
            prev = temp;
        }
        i++;
    }
};

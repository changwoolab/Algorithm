class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 1. Validate Row
        for (int i = 0; i < 9; i++) {
            int arr[9] = { 0 };
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int value = board[i][j] - '1';
                if (arr[value] != 0) return false;
                arr[value] = 1;
            }
        }

        // 2. Validate Column
        for (int i = 0; i < 9; i++) {
            int arr[9] = { 0 };
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                int value = board[j][i] - '1';
                if (arr[value] != 0) return false;
                arr[value] = 1;
            }
        }

        // 3. Validate 3 x 3 sub-boxes
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int arr[10] = { 0 };
                for (int k = 0; k < 3; k++) {
                    for (int p = 0; p < 3; p++) {
                        if (board[i*3 + k][j*3 + p] == '.') continue;
                        int value = board[i*3 + k][j*3 + p] - '1';
                        if (arr[value] != 0) return false;
                        arr[value] = 1;
                    }
                }
            }
        }

        return true;
    }
};

// https://leetcode.com/problems/game-of-life/solutions/4514744/c-o-1-space-complexity-solution/

class Solution {
private:
    const int DEAD = 0;
    const int ALIVE = 1;
    const int WAS_ALIVE_GOING_DEAD = 2;
    const int WAS_DEAD_GOING_ALIVE = 3;
    const vector<pair<int, int>> d = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    int getNeighborCnt(vector<vector<int>>& board, int rowSize, int colSize, int i, int j) {
        int neighborCnt = 0;

        for (auto& [di, dj] : d) {
            int ni = i + di;
            int nj = j + dj;

            if (ni < 0 || ni >= rowSize || nj < 0 || nj >= colSize) {
                continue;
            }

            if (board[ni][nj] == ALIVE || board[ni][nj] == WAS_ALIVE_GOING_DEAD) {
                neighborCnt++;
            }
        }

        return neighborCnt;
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        int rowSize = board.size();
        int colSize = board[0].size();

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                int neighborCnt = getNeighborCnt(board, rowSize, colSize, i, j);

                if (board[i][j] == ALIVE || board[i][j] == WAS_ALIVE_GOING_DEAD) {
                    // currently ALIVE
                    if (neighborCnt < 2 || neighborCnt > 3) board[i][j] = WAS_ALIVE_GOING_DEAD;
                } else {
                    // currently DEAD
                    if (neighborCnt == 3) board[i][j] = WAS_DEAD_GOING_ALIVE;
                }
            }
        }
        
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (board[i][j] == WAS_ALIVE_GOING_DEAD) board[i][j] = DEAD;
                else if (board[i][j] == WAS_DEAD_GOING_ALIVE) board[i][j] = ALIVE;
            }
        }
    }
};

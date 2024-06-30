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
#define pi pair<int, int>
#define NOT_DEFINED 987654321

using namespace std;

int sudoku[9][9];
bool solved = false;

bool checkRow(int num, int row, int col) {
  for (int i = 0; i < 9; i++) {
    if (sudoku[row][i] == num) {
      return false;
    }
  }
  return true;
}

bool checkCol(int num, int row, int col) {
  for (int i = 0; i < 9; i++) {
    if (sudoku[i][col] == num) {
      return false;
    }
  }
  return true;
}

bool check3x3(int num, int row, int col) {
  int startRow = (row / 3) * 3;
  int startCol = (col / 3) * 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (sudoku[startRow + i][startCol + j] == num) return false;
    }
  }
  return true;
}

void solve(int row, int col) {
  if (row >= 9 || row < 0 || col >= 9 || col < 0) return;
  if (solved) return;

  if (sudoku[row][col] != 0) {
    if (row == 8 && col == 8) {
      solved = true;
      return;
    }else if (col == 8) {
      solve(row + 1, 0);
    } else {
      solve(row, col + 1);
    }
    return;
  }
  
  // sudoku[row][col] == 0 인 경우만 여기 체크
  for (int i = 1; i <= 9; i++) {
    if (checkRow(i, row, col) && checkCol(i, row, col) && check3x3(i, row, col)) {
      sudoku[row][col] = i;
      if (row == 8 && col == 8) {
        solved = true;
        return;
      } else if (col == 8) {
        solve(row + 1, 0);
      } else {
        solve(row, col + 1);
      }
      if (solved) return;
      sudoku[row][col] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 9; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 9; j++) {
      sudoku[i][j] = s[j] - '0';
    }
  }

  solve(0, 0);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << sudoku[i][j];
    }
    cout << '\n';
  }

  return 0;
}

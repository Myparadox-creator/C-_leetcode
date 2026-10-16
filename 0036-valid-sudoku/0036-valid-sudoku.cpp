class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    continue;
                }

                for(int k = j + 1; k < 9; k++) {
                    if(board[i][j] == board[i][k]) {
                        return false;
                    }
                }
            }
        }

        for(int j = 0; j < 9; j++) {
            for(int i = 0; i < 9; i++) {
                if(board[i][j] == '.') {
                    continue;
                }

                for(int k = i + 1; k < 9; k++) {
                    if(board[i][j] == board[k][j]) {
                        return false;
                    }
                }
            }
        }

        // Check 3 x 3 sub-boxes
        for(int row = 0; row < 9; row += 3) {
            for(int col = 0; col < 9; col += 3) {

                for(int i = row; i < row + 3; i++) {
                    for(int j = col; j < col + 3; j++) {

                        if(board[i][j] == '.') {
                            continue;
                        }

                        for(int x = row; x < row + 3; x++) {
                            for(int y = col; y < col + 3; y++) {

                                if(i == x && j == y) {
                                    continue;
                                }

                                if(board[i][j] == board[x][y]) {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int rowcase[9][9] = {0}; // Row case
        int colcase[9][9] = {0}; // Column case
        int gridcase[9][9] = {0}; // 3x3 grid case

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] != '.'){
                    int number = board[i][j] - '0';

                    int k = (i/3) * 3 + (j/3); // Calculate the grid index
                    if(rowcase[i][number-1]++ || colcase[j][number-1]++ || gridcase[k][number-1]++ ){
                        return false; // If the number already exists in the row, column, or grid, return false
                    }
                }
            }
        }
        return true; // If no duplicates found, the Sudoku is valid
    }
};

Time Complexity	O(1)
Space Complexity	O(1)

Even though you use arrays, both time and space complexities are constant due to the fixed size of the board.

//Explanation:
// The function isValidSudoku checks if a given 9x9 Sudoku board is valid.
// It uses three 2D arrays to keep track of the numbers seen in each row, column, and 3x3 grid.
// For each cell in the board, if it contains a number (not '.'), it checks if that number has already been seen in the corresponding row, column, or grid.
// If any number is found more than once in any of these, the function returns false.
// If no duplicates are found after checking all cells, it returns true, indicating the Sudoku board is valid.
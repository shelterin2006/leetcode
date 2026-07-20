class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> rotatedGrid(
            row, vector<int>(col));

        int rotation = k % (row * col);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                int currCol = (j + rotation) % col;
                int currRow =
                    (i + (j + rotation) / col) % row;

                rotatedGrid[currRow][currCol] =
                    grid[i][j];
            }
        }

        return rotatedGrid;
    }
};
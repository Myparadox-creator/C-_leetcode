class Solution {
public:

    bool dfs(vector<vector<int>>& grid, int i, int j) {

        // If we go outside the grid, the island is not closed
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return false;
        }

        // If the cell is water, this direction is safe
        if (grid[i][j] == 1) {
            return true;
        }

        // Mark the land cell as visited
        grid[i][j] = 1;

        // Explore all four directions
        bool up = dfs(grid, i - 1, j);
        bool down = dfs(grid, i + 1, j);
        bool left = dfs(grid, i, j - 1);
        bool right = dfs(grid, i, j + 1);

        // The island is closed only if all directions are closed
        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) {

                    if (dfs(grid, i, j)) {
                        count++;
                    }

                }
            }
        }

        return count;
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                count += sink(i, j, grid);
            }
        }
        return count;
    }

    int sink(int i, int j, vector<vector<char>> &grid) {
        if (0 <= i && i < grid.size() && 0 <= j && j < grid[i].size() && grid[i][j] == '1') {
            grid[i][j] = '0';
            sink(i + 1, j, grid);
            sink(i - 1, j, grid);
            sink(i, j + 1, grid);
            sink(i, j - 1, grid);
            return 1;
        }
        return 0;
    }

};
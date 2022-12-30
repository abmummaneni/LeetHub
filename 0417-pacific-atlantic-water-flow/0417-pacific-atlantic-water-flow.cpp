class Solution {
public:
    unordered_map<int, unordered_map<int, bool>> pacific;
    unordered_map<int, unordered_map<int, bool>> atlantic;

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {

        vector<vector<int>> ans;
        for (int i = 0; i < heights.size(); ++i) {
            for (int j = 0; j < heights[i].size(); ++j) {
                pacific.clear();
                atlantic.clear();
                if (canPacific(i, j, heights, INT_MAX) && canAtlantic(i, j, heights, INT_MAX)) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    bool canPacific(int i, int j, vector<vector<int>> &heights, int prev) {

        if (0 <= i && i < heights.size() && 0 <= j && j < heights[i].size()) {
            if (heights[i][j] > prev) { return false; }
            else if (pacific[i].find(j) != pacific[i].end()) { return pacific[i][j]; }
            else if (i == 0 || j == 0) { pacific[i][j] = true; }
            else {
                int curr = heights[i][j];
                pacific[i][j] = false;
                pacific[i][j] = canPacific(i + 1, j, heights, curr) || canPacific(i - 1, j, heights, curr) ||
                                canPacific(i, j + 1, heights, curr) || canPacific(i, j - 1, heights, curr);
            }
            return pacific[i][j];
        }
        return false;
    }

    bool canAtlantic(int i, int j, vector<vector<int>> &heights, int prev) {
        if (0 <= i && i < heights.size() && 0 <= j && j < heights[i].size()) {
            if (atlantic[i].find(j) != atlantic[i].end()) { return atlantic[i][j]; }
            else if (heights[i][j] > prev) { return false; }
            else if (i == heights.size() - 1 || j == heights[i].size() - 1) { atlantic[i][j] = true; }
            else {
                int curr = heights[i][j];
                atlantic[i][j] = false;
                atlantic[i][j] = canAtlantic(i + 1, j, heights, curr) || canAtlantic(i - 1, j, heights, curr) ||
                                 canAtlantic(i, j + 1, heights, curr) || canAtlantic(i, j - 1, heights, curr);
            }
            return atlantic[i][j];
        }
        return false;
    }
};
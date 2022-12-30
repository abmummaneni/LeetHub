class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        vector<int> nums;
        for (auto & i : matrix) {
            nums.push_back(i[0]);
        }
        int row = std::upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        if(row < 0){return false;}
        nums = matrix[row];
        return std::binary_search(nums.begin(), nums.end(),target);
    }
};
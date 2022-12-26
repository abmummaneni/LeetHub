class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);
        for (int i = 1, j = nums.size() - 2; j >= 0; ++i, --j) {
            prefix[i] = prefix[i - 1] * nums[i-1];
            suffix[j] = suffix[j + 1] * nums[j+1];
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = prefix[i] * suffix[i];
        }
        return nums;
    }
};
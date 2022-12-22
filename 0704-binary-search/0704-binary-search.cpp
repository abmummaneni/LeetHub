class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binSearch(nums, target, 0);
    }
    int binSearch(vector<int>& nums, int target,  int start){
        int mid = nums.size() / 2;
        if (nums.empty()){ return -1; }
        int curr = nums[mid];
        if (curr == target){
            return start + mid;
        }

        if (curr < target){
            nums.erase(nums.begin(), nums.begin() + mid + 1);
            return binSearch(nums, target, start + mid + 1);
        }
        if (curr > target){
            nums.erase(nums.begin() + mid, nums.end());
            return binSearch(nums, target, start);
        }
        return -1;
    }
};
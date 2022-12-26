class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumps = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if (jumps == 0){
                return false;
            }
            jumps--;
            if (nums[i] > jumps){
                jumps = nums[i];
            }
        }
        return true;
    }
};
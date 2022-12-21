class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        // for (int num : nums){
        //     std::cout << num << " ";
        // }
        // std::cout << endl;
        int n = nums.size();
        for (int i = 0; i < n; ++i){
            int num = nums.back();
            nums.pop_back();
            // for (int num : nums){
            //     std::cout << num << " ";
            // }
            // std::cout << endl;
            if(std::binary_search(nums.begin(), nums.end(), num)){
                return true;
            }
        }
        return false;
    }
};
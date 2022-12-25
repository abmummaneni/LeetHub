class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int total = INT_MIN, max = total;
        for (int num: nums) {
            total =  (num > total && total < 0) ? num : total + num;
            if (total > max) { max = total; }
        }
        return max;
    }
};
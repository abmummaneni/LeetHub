class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> heap(k, INT_MIN);
        for (int num : nums) {
            if(num > heap.top()){
                heap.pop();
                heap.push(num);
            }
        }
        return heap.top();
    }

};
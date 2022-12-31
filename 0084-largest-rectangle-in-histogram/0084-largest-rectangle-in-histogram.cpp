class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> todo;
        int maxArea = 0;
        int i = 0;
        heights.push_back(-1);
        while (i < heights.size()) {
            if (todo.empty() || heights[i] >= heights[todo.top()]) {
                todo.push(i++);
            }
            else {
                int top = heights[todo.top()];
                todo.pop();
                int area = (todo.empty()) ? top * i : top * (i - todo.top() - 1);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
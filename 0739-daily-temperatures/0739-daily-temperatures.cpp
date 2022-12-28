class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> todo;
        for (int i = 0; i < temperatures.size(); i++) {
            for (; !todo.empty() && temperatures[i] > temperatures[todo.top()]; todo.pop()) {
                ans[todo.top()] = i - todo.top();
            }
            todo.push(i);
        }
        return ans;
    }
};
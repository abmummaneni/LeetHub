class Solution {
public:
    int carFleet(int target, vector<int> &positions, vector<int> &speeds) {
        stack<double> todo;
        map<double, int> mp;
        for (int i = 0; i < positions.size(); ++i) {
            mp[positions[i]] = speeds[i];
        }

        for (pair p: mp) {
            double t = (target - p.first) / p.second;
            while (!todo.empty() && t >= todo.top()) {
                todo.pop();
            }
            todo.push(t);

        }
        return todo.size();
    }
};
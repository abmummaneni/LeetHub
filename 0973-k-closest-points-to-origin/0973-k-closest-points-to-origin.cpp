class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        typedef pair<vector<int>, double> Data;
        priority_queue<Data, vector<Data>, function<bool(Data, Data)> > heap(
                [](const Data &a, const Data &b) { return a.second < b.second; });
        unordered_map<double, vector<int>> mp;
        vector<vector<int>> ans;
        for (auto &point: points) {
            double dist = sqrt(point[0] * point[0] + point[1] * point[1]);
            if (heap.size() < k) { heap.emplace(point, dist); }
            else if (dist < heap.top().second) {
                heap.pop();
                heap.emplace(point, dist);
            }
        }
        while (!heap.empty()) {
            ans.push_back(heap.top().first);
            heap.pop();
        }
        return ans;
    }
};
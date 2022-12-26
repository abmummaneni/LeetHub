class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        for (int num: nums) {
            mp[num]++;
        }
        vector<pair<int, int>> ordered;
        for (auto &[num, count]: mp) {
            ordered.emplace_back(count, num);
        }
        sort(ordered.begin(), ordered.end(), [](auto a, auto b) { return a.first > b.first; });
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(ordered[i].second);
        }
        return ans;
    }
};
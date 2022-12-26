class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hash;
        for (const auto &str: strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            hash[sorted].push_back(str);
        }
        for (auto &[sorted, v]: hash) {
            ans.push_back(v);
        }
        return ans;
    }
};
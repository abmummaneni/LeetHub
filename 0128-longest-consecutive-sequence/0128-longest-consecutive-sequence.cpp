class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int > mp;
        int longest = 0;
        for (int num: nums) {
            if (mp.find(num) != mp.end()) {
                continue;
            }
            if ((mp.find(num + 1) != mp.end() && mp.find(num - 1) != mp.end())) {
                mp[num] = mp[num - 1] + 1 + mp[num + 1];
                mp[num - mp[num - 1]] = mp[num + mp[num + 1]] = mp[num];
            }
            else if (mp.find(num + 1) != mp.end()) {
                mp[num] = 1 + mp[num + 1];
                mp[num + mp[num + 1]] = mp[num];
            }
            else if (mp.find(num - 1) != mp.end()) {
                mp[num] = mp[num - 1] + 1;
                mp[num - mp[num - 1]] = mp[num];
            }
            else { mp[num] = 1; }
            longest = max(longest, mp[num]);
        }
        return longest;
    }
};
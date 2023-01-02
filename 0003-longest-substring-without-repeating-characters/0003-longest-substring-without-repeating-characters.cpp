class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int curr = 0;
        int maxLength = 0;
        char c;
        for (int i = 0; i < s.size(); i++) {
            c = s[i];
            if (mp[c]){
                i = mp[c] - 1;
                mp.clear();
                curr = 0;
            }
            else{
                mp[c] = i + 1;
                curr++;
                maxLength = max(maxLength, curr);
            }
        }
        return maxLength;
    }
};
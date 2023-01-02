class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allCaps = 90 >= word[0];
        bool allLower = 97 <= word[0];
        bool normal = 90 >= word[0];
        for (int i = 1; i < word.size(); i++) {
            if (word[i] >= 97) { allCaps = false; }
            else { allLower = normal = false; }
        }
        return allCaps || allLower || normal;
    }
};
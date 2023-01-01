class Solution {
public:
    bool wordPattern(const string &pattern, const string &s) {
        stringstream ss(s);
        string word;
        unordered_map<string, char> stc;
        unordered_map<char, string> cts;
        for (auto c: pattern) {
            if (!(ss >> word)) { return false; }
            if (stc.find(word) == stc.end()) {
                if (cts.find(c) != cts.end()) { return false; }
                stc[word] = c;
                cts[c] = word;
            }
            else if (cts.find(c) == cts.end()) {
                if (stc.find(word) != stc.end()) { return false; }
                stc[word] = c;
                cts[c] = word;
            }
            if (stc[word] != c || cts[c] != word) { return false; }

        }
        return (ss && !(ss >> word));
    }
};
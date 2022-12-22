class Solution {
public:
    bool isPalindrome(string s) {
        string clean;
        for (auto c : s){
            if (isalnum(c)){
                clean += tolower(c);
            }
        }
        string copy(clean);
        std::reverse(copy.begin(), copy.end());
        return (copy == clean);
    }
};
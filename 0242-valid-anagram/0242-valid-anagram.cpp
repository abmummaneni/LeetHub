class Solution {
public:
    bool isAnagram(string s, string t) {
        for(char c: s){
            if (t.empty()){return false;}
            int index = t.find(c);
            if (index == -1){ return false;}
            t.erase(index, 1);
        }
        return t.empty();
    }
};
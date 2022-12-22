class Solution {
public:
    bool isValid(string s) {
        vector<int> queue;
        string open = "({[";
        string close = ")}]";
        for (char c : s){
            int opos = open.find(c);
            if(opos != string::npos){
                queue.push_back(opos);
                continue;
            }
            int cpos = close.find(c);
            if(cpos != string::npos){
                if (queue.empty()){ return false;}
                if (cpos != queue.back()){ return false; }
                queue.pop_back();
            }
        }
        return queue.empty();
    }
};
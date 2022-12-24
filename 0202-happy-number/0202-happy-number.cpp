class Solution {
public:
    bool isHappy(int n) {
        vector<int> seen;
        return recurHappy(n, seen);
    }
    bool recurHappy(int n, vector<int> seen ){
        if(n ==1){ return true;}
        if(find(seen.begin(), seen.end(), n) != seen.end()){
            return false;
        }
        seen.push_back(n);
        string digits;
        digits = to_string(n);
        int sum = 0;
        for (int i = 0; i < digits.length(); ++i){
            sum += pow(digits[i] - '0', 2);
        }
        return recurHappy(sum, seen);
    }
};
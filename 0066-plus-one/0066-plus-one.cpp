class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty()){
            digits.push_back(1);
            return digits;
        }
        if (digits.back() != 9){
            digits.back() += 1;
            return digits;
        }
        digits.pop_back();
        vector<int> newDigits = plusOne(digits);
        newDigits.push_back(0);
        return newDigits;
    }
};
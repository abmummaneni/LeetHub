class Solution {
public:
    int numTilings(int n) {
        
        if (n == 0){ return 1;}
        if (n == 1){ return 1;}
        if (n == 2){ return 2;}
        deque<int> d;
        d.push_back(1);
        d.push_back(1);
        d.push_back(2);
        int modulus = pow(10,9) + 7;
        for(int i = 3; i <= n; i++ ){
            d.push_back( ((2*d.back() %  modulus + d.front() %  modulus) %  modulus));
            d.pop_front();
        }
        return d.back();
    }
};
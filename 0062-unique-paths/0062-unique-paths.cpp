
class Solution {
public:
    int uniquePaths(int m, int n) {
        double ans = 1;
        for(double i = 1; i <= m - 1; i++){
            ans *= (((double) n - 1) / i + 1);
        }
        ans += 0.5; // round
        return (int) ans;
    }
};
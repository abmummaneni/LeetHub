class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2){
            return n;
        }
        int two_steps_away = 1;
        int one_step_away = 2;
        int total = 0;
        for (int i = 3; i < n + 1; ++i){
            total = two_steps_away + one_step_away;
            two_steps_away = one_step_away;
            one_step_away = total;
        }
        return total;
    }
    
};
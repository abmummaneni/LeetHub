class Solution {
public:
    int minCostClimbingStairs(vector<int> cost) {
        int oneStep = cost[1];
        int twoStep = cost[0];
        int curr = 0;
        for (int i = 2; i < cost.size(); ++i) {
            curr = min(twoStep, oneStep) + cost[i];
            twoStep = oneStep;
            oneStep = curr;
        }
        return min(oneStep, twoStep);
    }
};
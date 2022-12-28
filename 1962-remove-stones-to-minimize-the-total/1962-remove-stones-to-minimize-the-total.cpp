class Solution {
public:
    int minStoneSum(vector<int> &piles, int k) {
        priority_queue<int, vector<int>, greater<> > maxs(k, INT_MIN);
        int total = 0;
        for (int &pile: piles) {
            total += pile;
            while (pile > maxs.top()) {
                maxs.push(pile);
                maxs.pop();
                pile -= pile / 2;
            }
        }
        while (!maxs.empty()) {
            total -= maxs.top() / 2;
            maxs.pop();
        }
        return total;
    }
};
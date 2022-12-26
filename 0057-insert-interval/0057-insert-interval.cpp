class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int start = newInterval[0];
        int end = newInterval[1];
        int sindex = 0;
        int eindex = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] <= start && start <= intervals[i][1]) {
                sindex = i;
                eindex = i + 1;
                start = intervals[i][0];
            }
            if (intervals[i][0] <= end && end <= intervals[i][1]) {
                eindex = i + 1;
                end = intervals[i][1];
            }
            if (intervals[i][1] < start) {
                sindex = i + 1;
            }
            if (intervals[i][1] < end) {
                eindex = i + 1;
            }
        }
        if (start == newInterval[0] && end == newInterval[1] && sindex == eindex) {
            intervals.insert(intervals.begin() + sindex, 1, newInterval);
        }
        else {
            intervals.erase(intervals.begin() + sindex, intervals.begin() + eindex);
            vector<int> changed = {start, end};
            intervals.insert(intervals.begin() + sindex, 1, changed);
        }
        return intervals;
    }
};
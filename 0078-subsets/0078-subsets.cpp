class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> answers;
        vector<int> empty;
        answers.push_back(empty);
        for (int num: nums) {
            vector<vector<int>> temp;
            for (vector<int> ans: answers) {
                ans.push_back(num);
                temp.push_back(ans);
            }
            for (vector<int> t: temp) {
                answers.push_back(t);
            }
        }
        return answers;
    }
};
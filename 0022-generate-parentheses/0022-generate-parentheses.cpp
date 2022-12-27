class Solution {
public:
    vector<string> generateParenthesis(int n) {
        unordered_map<int, vector<string>> dp;
        dp[0].emplace_back("");
        dp[1].emplace_back("()");
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for(auto &inside: dp[j]){
                    for(auto &outside : dp[i - j - 1]){
                        dp[i].push_back("(" + inside + ")" + outside);
                    }
                }
            }
        }
        return dp[n];
    }
};
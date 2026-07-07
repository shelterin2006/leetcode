class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        // int dp[100001] = {};
        // for(int i = 0; i < questions.size(); i++){
        //     dp[i + questions[i][1] + 1] = max(dp[i + questions[i][1]], dp[i] + questions[i][0]);
        // }
        // int ans = 0;
        // for(int i = 0; i < questions.size(); i++) ans = max(ans, dp[i]);
        // return ans;
        int n = questions.size();
        vector<long long> dp(n + 5, 0);
        dp[min(n, questions[0][1] + 1)] = questions[0][0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i], dp[i - 1]);
            int p = min(n, i + questions[i][1] + 1);
            dp[p] = max(dp[p], dp[i] + questions[i][0]);
        }
        dp[n] = max(dp[n - 1], dp[n]);
        return dp[n];
    }

};
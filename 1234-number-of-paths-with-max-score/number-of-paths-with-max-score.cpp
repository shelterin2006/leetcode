class Solution {
public:
    int c(char t){
        if(t == 'E' || t == 'S') return 0;
        if(t == 'X') return -1;
        return t - '0';
    }
    int tong(int s, int t){
        if(s == -1 || t == -1) return -1;
        return s + t;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int dp[102][102];
        for(int i = 0; i < 102; i++) for(int j = 0; j < 102; j++) dp[i][j] = -1;
        int a[100][100];
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                a[i][j] = c(board[i][j]);
            }
        }
        dp[n - 1][m - 1] = 0;
        int way[102][102] = {};
        way[n - 1][m - 1] = 1;
        vector <int> ans;
        int mod = 1e9 + 7;
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(i + 1 < n && j + 1 < m) {
                    int maxS = tong(dp[i + 1][j + 1], a[i][j]);
                    if(maxS > dp[i][j]){
                        dp[i][j] = maxS;
                        way[i][j] = way[i + 1][j + 1];
                        way[i][j] %= mod;
                    } else if(maxS == dp[i][j]) {
                        way[i][j] += way[i + 1][j + 1];
                        way[i][j] %= mod;
                    }
                }
                if(j + 1 < m){
                    int maxS = tong(dp[i][j + 1], a[i][j]);
                    if(maxS > dp[i][j]){
                        dp[i][j] = maxS;
                        way[i][j] = way[i][j + 1];
                        way[i][j] %= mod;
                    } else if(maxS == dp[i][j]) {
                        way[i][j] += way[i][j + 1];
                        way[i][j] %= mod;
                    }
                }
                if(i + 1 < n) {
                    int maxS = tong(dp[i + 1][j], a[i][j]);
                    if(maxS > dp[i][j]){
                        dp[i][j] = maxS;
                        way[i][j] = way[i + 1][j];
                        way[i][j] %= mod;
                    } else if(maxS == dp[i][j]) {
                        way[i][j] += way[i + 1][j];
                        way[i][j] %= mod;
                    }
                }
            }
        }
        ans.push_back(dp[0][0]);
        ans.push_back(way[0][0]);
        if(ans[0] == -1){
            ans[0] = ans[1] = 0;
        }
        return ans;
    }
};
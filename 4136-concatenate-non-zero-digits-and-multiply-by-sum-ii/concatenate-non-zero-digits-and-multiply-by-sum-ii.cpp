class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long mod = 1000000007;
        int n = s.length();
        string t = "";
        t.reserve(n);
        vector<int> left_nonzero(n, -1);
        vector<int> right_nonzero(n, -1);
        vector<int> anhxa(n, -1);
        int d = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                left_nonzero[i] = d;
            } else {
                anhxa[i] = t.length();
                d = i;
                t.push_back(s[i]);
                left_nonzero[i] = d;
            }
        }
        d = -1;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '0'){
                right_nonzero[i] = d;
            } else {
                d = i;
                right_nonzero[i] = d;
            }
        }
        int q = queries.size();
        vector<int> ans;
        ans.reserve(q);
        int m = t.size();
        vector<long long> P10(m + 1, 1);
        vector<long long> pref_sum(m + 1, 0);
        vector<long long> pref_hash(m + 1, 0);
        for(int i = 0; i < m; i++) {
            P10[i + 1] = (P10[i] * 10) % mod;
            pref_sum[i + 1] = (pref_sum[i] + (t[i] - '0')) % mod;
            pref_hash[i + 1] = (pref_hash[i] * 10 + (t[i] - '0')) % mod;
        }
        for(int i = 0; i < q; i++){
            int original_l = queries[i][0];
            int original_r = queries[i][1];
            int real_l = (original_l < n && original_l >= 0) ? right_nonzero[original_l] : -1;
            int real_r = (original_r < n && original_r >= 0) ? left_nonzero[original_r] : -1;
            if(real_l == -1 || real_r == -1 || real_l > original_r || real_r < original_l || real_l > real_r) {
                ans.push_back(0);
                continue;
            } 
            int a = anhxa[real_l] + 1; 
            int b = anhxa[real_r] + 1;
            long long sum = (pref_sum[b] - pref_sum[a - 1] + mod) % mod;
            long long x = (pref_hash[b] - (pref_hash[a - 1] * P10[b - a + 1]) % mod + mod) % mod;
            long long res = (sum * x) % mod;
            ans.push_back((int)res);
        }
        
        return ans;
    }
};
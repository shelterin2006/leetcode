constexpr int NE = 1e5 + 1;
pair<int, int> a[(int)1e5 + 1];
int pos[NE + 1];
int pa[NE][21];
class Solution {
public:
    int cnt(int a, int b){
        if(a == b) return 0;
        if(pa[a][0] >= b) return 1;
        int ans = 0;
        for(int i = 18; i >= 0; i--){
            if(pa[a][i] < b){
                a = pa[a][i];
                ans += (1 << i);
            }
        }
        if(pa[a][0] >= b){
            return ans + 1;
        }
        return -1;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        for(int i = 0; i < n; i++) a[i] = {nums[i], i};
        sort(a, a + n);
        for (int i=0; i<n; i++) pos[a[i].second]=i;
        int i = 0, j = 0;
        while(i < n){
            while(j + 1 < n && a[i].first + maxDiff >= a[j + 1].first) j++;
            pa[i][0] = j;
            i++; j = max(j, i);
        }
        for(int i = 1; i <= 18; i++){
            for(int j = 0; j < n; j++) {
                if (pa[j][i - 1] > -1) 
                    pa[j][i] = pa[pa[j][i - 1]][i - 1];
                else pa[j][i] = -1;     
            }
        }
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int a = queries[i][0], b = queries[i][1];
            a = pos[a], b = pos[b];
            if(a > b) swap(a, b);
            ans.push_back(cnt(a, b));
        }
        return ans;
    }
};
class Solution {
public:
    int p[100], si[100];
    int maxx = 1;
    int get(int a){
        return p[a] = (p[a] == a ? a : get(p[a]));
    }
    void uni(int a, int b){
        int x = get(a), y = get(b);
        if(si[x] > si[y]){
            swap(x, y);
        }
        p[x] = y; si[y] += si[x];
        maxx = max(maxx, si[y]);
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++) p[i] = i, si[i] = 1;
        for(int i = 0; i < edges.size(); i++){
            if(get(edges[i][0]) == get(edges[i][1])) continue;
            uni(edges[i][0], edges[i][1]);
        }
        pair<int, int> sum[60];
        for(int i = 0; i < n; i++){
            sum[get(i)].first++;
        }
        for(int i = 0; i < edges.size(); i++){
            sum[get(edges[i][0])].second++;
        }
        int ans = 0;
        bool pa[100] = {};
        for(int i = 0; i < n; i++){
            int f = get(i);
            if(pa[f] == 1) continue;
            pa[f] = 1;
            long long a = sum[f].first, b = sum[f].second;
            ans += (b == a * (a - 1)/2);
        }
        return ans;
    }
};
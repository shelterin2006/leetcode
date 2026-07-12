class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       int n = arr.size();
       vector<pair<int, int>> a;
       vector<int> ans(n);
        for(int i = 0; i < n; i++) a.push_back({arr[i], i});
        sort(a.begin(), a.end());
        int rank = 0;
        int maxx = -2147483647;
        for(int i = 0; i < n; i++){
            if(a[i].first > maxx){
                maxx = a[i].first;
                rank++;
            }
            ans[a[i].second] = rank;
        }
       return ans;
    }
};
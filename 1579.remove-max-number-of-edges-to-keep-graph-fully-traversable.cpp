/*
 * @lc app=leetcode id=1579 lang=cpp
 *
 * [1579] Remove Max Number of Edges to Keep Graph Fully Traversable
 */

// @lc code=start
class Solution {
public:
int p[100000 + 10], sz[100000 + 10];
int find(int x){
    return p[x] == x ? x : (p[x] = find(p[x]));
}
bool unite(int x, int y) {
    int x_root = find(x);
    int y_root = find(y);
    if (x_root == y_root) { return false; }
    if (sz[x_root] < sz[y_root]) { swap(x_root, y_root); }
    sz[x_root] += sz[y_root];
    p[y_root] = x_root;
    return true;
}
int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    int ans = 0;
    for (int i = 0; i <= n; i++) { p[i] = i; sz[i] = 1; }
    for(int i = 0; i < edges.size(); i++){
        if(edges[i][0] != 3) continue;
        if(unite(edges[i][1], edges[i][2]) == false) ans++;
    }
    int t[100000 + 10], t1[100000 + 10];
    for(int i = 0; i <= n; i++) t[i] = p[i], t1[i] = sz[i];
    for(int i = 0; i < edges.size(); i++){
        if(edges[i][0] == 3 || edges[i][0] == 2) continue;
        if(unite(edges[i][1], edges[i][2]) == false) ans++;
    }
    if(sz[find(1)] != n) return -1;
    for(int i = 0; i <= n; i++) p[i] = t[i], sz[i] = t1[i];
    for(int i = 0; i < edges.size(); i++){
        if(edges[i][0] == 3 || edges[i][0] == 1) continue;
        if(unite(edges[i][1], edges[i][2]) == false) ans++;
    }
    if(sz[find(1)] != n) return -1;
    return ans;
}
};
// @lc code=end


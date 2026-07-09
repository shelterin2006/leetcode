class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    vector<bool> res(queries.size());
    int color = 0, idx = 0;
    vector<int> colorArray(n, 0);
    for (int i = 1; i < n; i++) 
        colorArray[i] = (nums[i] - nums[i - 1] <= maxDiff) ? color : ++color;
    for (const auto& q : queries) 
        res[idx++] = (colorArray[q[0]] == colorArray[q[1]]);
    return res;
    }
};
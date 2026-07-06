class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
        });
        int ans = 0;
        int i = 0;
        for(; i < intervals.size(); ){
            int j = i + 1;
            while(j < intervals.size() && intervals[j][1] <= intervals[i][1]){
                j++;
            }
            ans++;
            i = j;
        }
        return ans;
    }
};
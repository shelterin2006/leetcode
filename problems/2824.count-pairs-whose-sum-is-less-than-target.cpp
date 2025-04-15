/*
 * @lc app=leetcode id=2824 lang=cpp
 *
 * [2824] Count Pairs Whose Sum is Less than Target
 */

// @lc code=start
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int ans = 0;
        vector<int> f;
        for(int i = 0; i < nums.size(); i++){
            f.push_back(nums[i]);
            sort(f.begin(), f.end());
            int t = target - a[i];
            if(f[0] > t) continue;
            int l = 0, r = i - 1;
            while(l < r){
                int mid = (l + r) / 2;
                if(f[mid] > target) r = mid - 1;
                else l = mid + 1;
            }
            ans += l;
        }
        return ans;
    }
};
// @lc code=end


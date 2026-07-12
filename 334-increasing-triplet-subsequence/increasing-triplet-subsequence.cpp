class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long a = LLONG_MAX, b = LLONG_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] <= a){
                a = nums[i];
            } else if(nums[i] <= b){
                b = nums[i];
            } else return true;
        }
        return false;
    }
};
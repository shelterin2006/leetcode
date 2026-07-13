class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        vector<int> all;
        int d = 0;
        for(int i = 1; i <= 9; i++){
            d = 0;
            for(int j = i; j <= 9; j++){
                d = d * 10 + j;
                all.push_back(d);
            }
        }
        sort(all.begin(), all.end());
        for(int i = 0; i < all.size(); i++){
            if(all[i] >= low && all[i] <= high) ans.push_back(all[i]);
        }
        return ans;
    }
};
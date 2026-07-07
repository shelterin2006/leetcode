class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        int dem[3000] = {};
        int ans = 1;
        int j = 0;
        dem[s[0]] = 1;
        for(int i = 1; i < s.size(); i++){
            dem[s[i]]++;
            while(dem[s[i]] > 1){
                dem[s[j]]--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
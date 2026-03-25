class Solution {
public:
    int lengthOfLastWord(string s) {
        s = s + ' ';
        int ans = 0;
        int dem = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                if(dem == 0) continue;
                ans = dem; dem = 0;
            } else dem++;
        }
        return ans;
    }
};
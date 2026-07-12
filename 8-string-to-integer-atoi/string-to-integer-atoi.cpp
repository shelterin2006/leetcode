class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int i = 0;
        while(s[i] == ' ') i++;
        int c = 1;
        bool duong = true;
        if(s[i] == '-' || s[i] == '+'){
            c = (s[i] == '+' ? 1 : 0);
            if(c == 0) duong = false;
            i++;
        }
        long long minn = -(1LL << 31), maxx = (1LL << 31) - 1;
        while(i < s.size()){
            if(s[i] > '9' || s[i] < '0') break;
            long long d = ans;
            int so = (s[i] - '0') * (duong ? 1 : -1);
            ans = ans * 10 + so;
            if(ans > maxx){
                ans =  maxx; break;
            }
            if(ans < minn){
                ans = minn; break;
            }
            if(ans > 0 && c != -1){
                ans = (c == 0 ? -ans : ans);
                c = -1;
            }
            // cout << ans << ' ' << d << ' ' << i << ' ' << s[i] - '0' << endl;
            i++;
        }
        return (int)ans;
    }
};
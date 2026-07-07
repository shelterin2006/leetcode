class Solution {
public:
    int getTime(string s){
        int i = 0;
        while(s[i] != '$') i++;
        i++;
        int h = (s[i + 0] - '0') * 10 + (s[i + 1] - '0');
        int m = (s[i + 3] - '0') * 10 + (s[i + 4] - '0');
        return h * 60 + m;
    }
    string getstring(string s){
        string ans = "";
        int i = 0; 
        while(s[i] != '$') {
            ans = ans + s[i];
            i++;
        }
        return ans;
    }

    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        vector<string> a;
        for(int i = 0; i < keyName.size(); i++) a.push_back(keyName[i] + '$' + keyTime[i]);
        std::sort(a.begin(), a.end(), [this](const string& a, const string& b) {
        string f = getstring(a);
        string d = getstring(b);
        if (f == d) return getTime(a) < getTime(b); 
        return f < d; 
        });
        int i = 1, j = 0;
        vector<string> ans;
        for(; i < keyName.size(); i++){
            if(getstring(a[i]) != getstring(a[j])){
                j = i; 
                continue;
            }
            while(j <= keyName.size() && i >= j && getTime(a[i]) - getTime(a[j]) > 60){
                j++;
            }
            if(i - j + 1 >= 3) {
                ans.push_back(getstring(a[i]));
                while(i < keyName.size() && getstring(a[j]) == getstring(a[i])) i++;
                j = i;
            }
        }
        return ans;
    }
};
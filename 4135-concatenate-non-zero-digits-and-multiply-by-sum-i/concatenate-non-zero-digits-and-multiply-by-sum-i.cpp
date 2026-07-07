class Solution {
public:
    long long sumAndMultiply(int n) {
        int m = n;
        int x = 0;
        int sum = 0;
        while(m){
            int d = m % 10;
            m /= 10;
            sum += d;
            int f = 0;
            if(d == 0) continue;
            if(x > 0) f = (int)pow(10, (int)std::log10(x) + 1) * d;
            else f = d;
            x = x + f;
        }
        return (long long)x * sum; 
    }
};
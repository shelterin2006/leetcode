class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 0, even = 0;
        for(int i = 0; i <= n * 2; i++){
            if(i % 2) odd += i;
            else even += i;
        }   
        return gcd(odd, even);
    }
};
class Solution {
public:
    int mod = 1337;

    int power(int a, int k) {
        int res = 1;
        a %= mod;

        for(int i = 0; i < k; i++) {
            res = (res * a) % mod;
        }

        return res;
    }

    int superPow(int a, vector<int>& b) {
        int result = 1;

        for(int digit : b) {
            result = power(result, 10) * power(a, digit) % mod;
        }

        return result;
    }
};
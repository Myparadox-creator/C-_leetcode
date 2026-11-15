class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        const int MOD = 1000000007;

        int even = 1;
        int odd = 0;

        int parity = 0;
        long long ans = 0;

        for(int i = 0; i < arr.size(); i++) {

            parity ^= (arr[i] % 2);

            if(parity == 1) {

                ans += even;
                odd++;

            }
            else {

                ans += odd;
                even++;

            }

            ans %= MOD;
        }

        return ans;
    }
};
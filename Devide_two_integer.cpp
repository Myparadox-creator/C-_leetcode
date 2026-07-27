class Solution{
public:
    int divide(int dividend, int divisor){

        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);

        long long ans = 0;

        while(dvd >= dvs){
            long long cnt = 0;

            while(dvd >= (dvs << (cnt + 1))){
                cnt++;
            }

            ans += (1LL << cnt);
            dvd = dvd - (dvs << cnt);
        }

        if((dividend < 0) ^ (divisor < 0))
            ans = -ans;

        return ans;
    }
};
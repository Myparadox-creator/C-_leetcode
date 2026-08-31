class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";

        bool nev = false;

        if(num < 0){
            nev = true;
            num = -num;
        }

        string ans = "";
          while (num > 0) {
            int digit = num % 7;

            ans += to_string(digit);

            num = num / 7;
        }

        reverse(ans.begin(), ans.end());

        if (nev) {
            ans = "-" + ans;
        }

        return ans;
        
    }
};
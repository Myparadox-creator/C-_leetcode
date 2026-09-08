class Solution {
public:
    int countCommas(int n) {
        int com = 0;

        for(int i=0; i<=n; i++){
            int digit = to_string(i).length();

            com = com + (digit - 1)/3;
        }

        return com;

    }
};
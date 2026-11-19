class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        int x = INT_MIN, y = INT_MIN, z = INT_MIN;

        for (int num : nums) {

            // Find 3 smallest elements
            if (num < a) {
                c = b;
                b = a;
                a = num;
            }
            else if (num < b) {
                c = b;
                b = num;
            }
            else if (num < c) {
                c = num;
            }

            // Find 3 largest elements
            if (num > x) {
                z = y;
                y = x;
                x = num;
            }
            else if (num > y) {
                z = y;
                y = num;
            }
            else if (num > z) {
                z = num;
            }
        }

        return min({x - c, y - b, z - a});
    }
};
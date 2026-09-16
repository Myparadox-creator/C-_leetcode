class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1) {

            // If we have already seen this number,
            // we are stuck in a cycle
            if (seen.count(n)) {
                return false;
            }

            seen.insert(n);

            // Separate digits
            int temp = n;
            int sum = 0;

            while (temp > 0) {
                int digit = temp % 10;       // get last digit
                sum += digit * digit;        // square and add
                temp = temp / 10;            // remove last digit
            }

            // Make sum the new number
            n = sum;
        }

        return true;
    }
};
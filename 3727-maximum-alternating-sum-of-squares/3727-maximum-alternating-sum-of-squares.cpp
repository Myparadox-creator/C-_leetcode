class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> squares;

        // Step 1: Calculate the square of each element
        for (int x : nums) {
            squares.push_back(1LL * x * x);
        }

        // Step 2: Sort the squares in ascending order
        sort(squares.begin(), squares.end());

        // Step 3: Calculate the maximum alternating sum
        long long sum = 0;
        int n = squares.size();

        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                sum -= squares[i];
            } else {
                sum += squares[i];
            }
        }

        return sum;
    }
};
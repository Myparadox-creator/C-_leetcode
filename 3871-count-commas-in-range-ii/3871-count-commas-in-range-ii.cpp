class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        // Start of the first range that contains commas
        long long start = 1000;

        // Numbers with 4-6 digits have 1 comma,
        // 7-9 digits have 2 commas, etc.
        long long commas = 1;

        while (start <= n) {
            
            // End of current digit range
            long long end = start * 1000 - 1;

            // Don't go beyond n
            end = min(end, n);

            // Number of integers in this range
            long long count = end - start + 1;

            // Every number has 'commas' commas
            ans += count * commas;

            // Move to next range
            start *= 1000;
            commas++;
        }

        return ans;
    }
};
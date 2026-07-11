class Solution {
public:
    // Function to create a palindrome from the prefix
    long long makePalindrome(long long prefix, bool isEven) {
        long long palindrome = prefix;

        if (!isEven) {
            prefix /= 10;
        }

        while (prefix > 0) {
            palindrome = palindrome * 10 + (prefix % 10);
            prefix /= 10;
        }

        return palindrome;
    }

    string nearestPalindromic(string n) {
        int len = n.size();
        long long num = stoll(n);

        unordered_set<long long> candidates;

        // Edge cases
        candidates.insert((long long)pow(10, len) + 1);
        candidates.insert((long long)pow(10, len - 1) - 1);

        // First half (prefix)
        long long prefix = stoll(n.substr(0, (len + 1) / 2));

        // Generate palindromes from prefix-1, prefix, prefix+1
        for (long long i = prefix - 1; i <= prefix + 1; i++) {
            candidates.insert(makePalindrome(i, len % 2 == 0));
        }

        // Remove the original number itself
        candidates.erase(num);

        long long ans = -1;

        for (long long candidate : candidates) {
            if (ans == -1 ||
                abs(candidate - num) < abs(ans - num) ||
                (abs(candidate - num) == abs(ans - num) && candidate < ans)) {
                ans = candidate;
            }
        }

        return to_string(ans);
    }
};
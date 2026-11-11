class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        // Minimum and maximum requirements
        int mn = min(need1, need2);
        int mx = max(need1, need2);

        // Case 1: Buy type 1 and type 2 separately
        long long costA = 1LL * need1 * cost1
                        + 1LL * need2 * cost2;

        // Case 2: Buy shared items for common requirements
        // and individual items for remaining requirements
        long long costB = 1LL * mn * costBoth
                        + 1LL * (need1 - mn) * cost1
                        + 1LL * (need2 - mn) * cost2;

        // Case 3: Buy only type 3 items
        long long costC = 1LL * mx * costBoth;

        // Return minimum possible cost
        return min({costA, costB, costC});
    }
};
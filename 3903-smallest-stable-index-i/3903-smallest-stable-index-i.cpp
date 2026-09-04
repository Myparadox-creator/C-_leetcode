class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n = nums.size();

        for (int i = 0; i < n; i++) {

            // Find maximum from index 0 to i
            int maxLeft = nums[0];

            for (int j = 0; j <= i; j++) {
                maxLeft = max(maxLeft, nums[j]);
            }

            // Find minimum from index i to n-1
            int minRight = nums[i];

            for (int j = i; j < n; j++) {
                minRight = min(minRight, nums[j]);
            }

            // Calculate instability score
            int score = maxLeft - minRight;

            // Check if index i is stable
            if (score <= k) {
                return i;
            }
        }

        return -1;
    }
};
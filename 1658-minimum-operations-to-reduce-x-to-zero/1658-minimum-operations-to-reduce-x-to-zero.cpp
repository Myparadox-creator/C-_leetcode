class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        // Calculate total sum
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        // Sum of the subarray that we want to keep
        int target = totalSum - x;

        // If target is negative,
        // it is impossible
        if (target < 0)
            return -1;

        int left = 0;
        int sum = 0;
        int maxLength = -1;

        for (int right = 0; right < n; right++) {

            sum += nums[right];

            // If sum becomes greater than target,
            // shrink the window
            while (left <= right && sum > target) {
                sum -= nums[left];
                left++;
            }

            // Found a subarray with sum = target
            if (sum == target) {
                int length = right - left + 1;
                maxLength = max(maxLength, length);
            }
        }

        // No valid subarray
        if (maxLength == -1)
            return -1;

        // Elements outside the subarray
        // are the ones we remove
        return n - maxLength;
    }
};
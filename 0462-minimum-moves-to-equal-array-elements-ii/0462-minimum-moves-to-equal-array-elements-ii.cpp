class Solution {
public:
    int minMoves2(vector<int>& nums) {

        long long mini = LLONG_MAX;

        for (int i = 0; i < nums.size(); i++) {

            long long moves = 0;

            // Assume nums[i] is the target
            int target = nums[i];

            for (int j = 0; j < nums.size(); j++) {

                moves += abs(nums[j] - target);

            }

            mini = min(mini, moves);
        }

        return mini;
    }
};
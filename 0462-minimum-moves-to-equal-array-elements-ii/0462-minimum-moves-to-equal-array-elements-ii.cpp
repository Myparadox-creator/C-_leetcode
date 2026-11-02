class Solution {
public:
    int minMoves2(vector<int>& nums) {

        int n = nums.size();

        // Find the median without fully sorting
        nth_element(nums.begin(),
                    nums.begin() + n / 2,
                    nums.end());

        int median = nums[n / 2];

        long long moves = 0;

        // Calculate total moves
        for (int i = 0; i < n; i++) {

            moves += abs((long long)nums[i] - median);
        }

        return (int)moves;
    }
};
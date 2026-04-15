<<<<<<< HEAD
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= target) {
                return i;
            }
        }
        return nums.size(); 
    }
=======
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= target) {
                return i;
            }
        }
        return nums.size(); 
    }
>>>>>>> 5d89016cc92f7edf396eb0ffe33f00ed3a88c3fd
};
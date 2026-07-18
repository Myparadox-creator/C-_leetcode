class Solution {
public:
    int gcd(int a, int b){
        if(b>a){
            return gcd(b, a);
        }
        else if(b==0){
            return a;
        }
        else{
            return gcd(b, a%b);
        }
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int min = nums[0];
        int max = nums[nums.size()-1];
        return gcd(min, max);
    }
};
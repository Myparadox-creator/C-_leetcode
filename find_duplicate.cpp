<<<<<<< HEAD
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;

        while(l<h){
            int m = (l+h)/2;

            int co = 0;
            for(int n : nums){
                if(n<=m) co++;
            }
            if(co > m){
            h = m;
        }
        else{
            l = m + 1;
        }
        }
        

        return l;
    }
=======
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;

        while(l<h){
            int m = (l+h)/2;

            int co = 0;
            for(int n : nums){
                if(n<=m) co++;
            }
            if(co > m){
            h = m;
        }
        else{
            l = m + 1;
        }
        }
        

        return l;
    }
>>>>>>> 5d89016cc92f7edf396eb0ffe33f00ed3a88c3fd
};
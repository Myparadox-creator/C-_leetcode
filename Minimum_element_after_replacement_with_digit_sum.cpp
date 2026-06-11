class Solution {
public:
    int minElement(vector<int>& nums) {
        vector<int> st;
        
        for(int i=0; i<nums.size(); i++){

                int sum = 0;
            if(nums[i]>=0 && nums[i]<=9){
                st.push_back(nums[i]);
            }
            else{
                while(nums[i]>0){
                    sum += nums[i]%10;
                    nums[i]/= 10;
                }
                st.push_back(sum);
            }
        }
        return *min_element(st.begin(), st.end());
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = matrix.size();
        int j = matrix[0].size();

        int rowi = 0;
        int coli = j - 1;

        while(rowi < i && coli >= 0){

            int element = matrix[rowi][coli];

            if(element == target){
                return 1;
            }
            if(element < target){
                rowi++;
            }
            else{
                coli--;
            }
        }

        return 0;
    }
};
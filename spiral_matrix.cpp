class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> st;
        int i = matrix.size();
        int j = matrix[0].size();

        int count = 0;
        int total = i * j;

        int sr = 0;
        int sc = 0;
        int er = i - 1;
        int ec = j - 1;

        while(count < total){

            // Starting row
            for(int index = sc; count < total && index <= ec; index++){
                st.push_back(matrix[sr][index]);
                count++;
            }
            sr++;

            // Ending column
            for(int index = sr; count < total && index <= er; index++){
                st.push_back(matrix[index][ec]);
                count++;
            }
            ec--;

            // Ending row
            for(int index = ec; count < total && index >= sc; index--){
                st.push_back(matrix[er][index]);
                count++;
            }
            er--;

            // Starting column
            for(int index = er; count < total && index >= sr; index--){
                st.push_back(matrix[index][sc]);
                count++;
            }
            sc++;
        }

        return st;
    }
};
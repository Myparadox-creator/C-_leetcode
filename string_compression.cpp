class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0; // starting of character index 
        int ansIndx = 0;

        while(i < chars.size()){
            int j = i + 1;
            while(j< chars.size() && chars[i]==chars[j]){
                j++;
            }

            chars[ansIndx++] = chars[i];
            int count = j-i;

            if(count > 1){
                string cnt = to_string(count);
                for(char ch : cnt){
                    chars[ansIndx++] = ch;
                }

            }

            i = j;
        }
         
         return ansIndx;
    }
};
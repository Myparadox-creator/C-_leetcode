class Solution {
public:
    long calculate(string s) {
        stack<long> st;
        long result = 0, number = 0, sign = 1;

        for(char c : s) {
            if(isdigit(c)) {
                number = number * 10 + (c - '0');
            }
            else if(c == '+') {
                result += sign * number;
                sign = 1;
                number = 0;
            }
            else if(c == '-') {
                result += sign * number;
                sign = -1;
                number = 0;
            }
            else if(c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if(c == ')') {
                result += sign * number;

                if(!st.empty()) {
                    result *= st.top();
                    st.pop();
                }
                if(!st.empty()) {
                    result += st.top();
                    st.pop();
                }

                number = 0;
            }
        }

        result += sign * number;
        return result;
    }
};
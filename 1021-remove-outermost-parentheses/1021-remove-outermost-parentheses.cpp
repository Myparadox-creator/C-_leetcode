class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";

        for (char ch : s) {

            if (ch == '(') {
                st.push(ch);

                // If stack size > 1, this is not outermost
                if (st.size() > 1) {
                    ans += ch;
                }
            }
            else {
                // If stack size > 1, this is not outermost
                if (st.size() > 1) {
                    ans += ch;
                }

                st.pop();
            }
        }

        return ans;
    }
};
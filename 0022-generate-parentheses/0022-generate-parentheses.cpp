class Solution {
public:
    bool isValid(string s) {
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                count++;
            } else {
                count--;
            }

            // A closing parenthesis appeared before an opening one.
            if (count < 0) {
                return false;
            }
        }

        return count == 0;
    }

    void generate(string current, int n, vector<string>& ans) {
        // Generate strings of length 2*n.
        if (current.length() == 2 * n) {
            if (isValid(current)) {
                ans.push_back(current);
            }
            return;
        }

        // Try adding an opening parenthesis.
        generate(current + '(', n, ans);

        // Try adding a closing parenthesis.
        generate(current + ')', n, ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        generate("", n, ans);

        return ans;
    }
};
class Solution {
public:
    void generate(string &current, int open, int close, int n,
                  vector<string> &ans) {

        // Base case
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Add opening parenthesis
        if (open < n) {
            current.push_back('(');

            generate(current, open + 1, close, n, ans);

            current.pop_back();
        }

        // Add closing parenthesis
        if (close < open) {
            current.push_back(')');

            generate(current, open, close + 1, n, ans);

            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current = "";

        generate(current, 0, 0, n, ans);

        return ans;
    }
};
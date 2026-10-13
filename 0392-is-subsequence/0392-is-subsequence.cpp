class Solution {
public:
    bool isSubsequence(string s, string t) {

        int j = 0;

        for (int i = 0; i < s.length(); i++) {
            bool found = false;

            for (; j < t.length(); j++) {
                if (s[i] == t[j]) {
                    found = true;
                    j++;
                    break;
                }
            }

            if (!found) {
                return false;
            }
        }

        return true;
    }
};
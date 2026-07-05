class Solution {
public:
    string removeDuplicates(string s) {
        int i=0;
        stack<char>ft;
        while(i< s.length()){
            if(ft.empty() || ft.top()!=s[i]){
                ft.push(s[i]);
            }
            else{
                ft.pop();
            }
            i++;
        }
         string ans = "";
         if(!ft.empty()){
            char el = ft.top();
            ft.pop();
            ans += el;
        }
         reverse(ans.begin(), ans.end());
         return ans;
    }
};
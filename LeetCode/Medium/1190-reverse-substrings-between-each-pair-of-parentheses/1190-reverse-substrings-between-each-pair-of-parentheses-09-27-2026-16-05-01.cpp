class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> match(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')') {
                int j = st.top();
                st.pop();
                match[i] = j;
                match[j] = i;
            }
        }
        string ans;
        int dir = 1;
        for(int i = 0; i < n; i += dir) {
            if(s[i] == '(' || s[i] == ')') {
                i = match[i];
                dir = -dir;
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};
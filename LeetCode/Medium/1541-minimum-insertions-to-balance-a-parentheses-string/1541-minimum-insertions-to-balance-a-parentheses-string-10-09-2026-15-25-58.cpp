
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int ans = 0;
        stack<char> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(s[i]);
            }
            else if (s[i] == ')') {
                if (i == n-1 || s[i + 1] != ')') {
                    // Need another ')' to form a pair.
                    ans++;
                    if (stk.empty()) {
                        // Insert a matching '('.
                        ans++;
                    } else {
                        stk.pop();
                    }
                }
                else {
                    // Found a pair '))'.
                    if (stk.empty()) {
                        // Insert a matching '('.
                        ans++;
                    } else {
                        stk.pop();
                    }
                    i++;
                }
            }
        }

        // Each remaining '(' needs two ')'.
        ans += 2 * stk.size();
        return ans;
    }
};

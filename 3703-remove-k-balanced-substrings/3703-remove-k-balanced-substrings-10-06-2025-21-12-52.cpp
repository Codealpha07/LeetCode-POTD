class Solution {
public:
    string removeSubstring(string s, int k) {
        string st;
        for (char c : s) {
            st.push_back(c);
            if (st.size() >= 2 * k) {
                bool ok = true;
                for (int i = 0; i < k; ++i) {
                    if (st[st.size() - 2*k + i] != '(') { ok = false; break; }
                }
                for (int i = 0; i < k; ++i) {
                    if (st[st.size() - k + i] != ')') { ok = false; break; }
                }
                if (ok) {
                    st.erase(st.end() - 2*k, st.end());
                }
            }
        }
        return st;
    }
};

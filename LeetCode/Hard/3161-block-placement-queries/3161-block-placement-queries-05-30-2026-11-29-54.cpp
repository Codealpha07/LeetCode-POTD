class Solution {
public:
    vector<int> seg; // segment tree storing maximum gap

    // Point update:
    // gap[idx] = val
    void update(int idx, int val, int p, int l, int r) {

        // Leaf node
        if (l == r) {
            seg[p] = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(idx, val, p << 1, l, mid);
        else
            update(idx, val, p << 1 | 1, mid + 1, r);

        // Maintain maximum gap
        seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
    }

    // Range maximum query
    int query(int L, int R, int p, int l, int r) {

        if (L <= l && r <= R)
            return seg[p];

        int mid = (l + r) >> 1;
        int res = 0;

        if (L <= mid)
            res = max(res, query(L, R, p << 1, l, mid));

        if (R > mid)
            res = max(res, query(L, R, p << 1 | 1, mid + 1, r));

        return res;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {

        int mx = 50000;

        seg.resize(mx << 2);

        // Obstacles
        set<int> st = {0, mx};

        // Initial gap:
        // [0,50000]
        update(mx, mx, 1, 0, mx);

        vector<bool> ans;

        for (auto &q : queries) {

            // Insert obstacle
            if (q[0] == 1) {

                int x = q[1];

                auto it = st.upper_bound(x);

                int r = *it;         // next obstacle
                int l = *prev(it);   // previous obstacle

                // new left interval
                update(x, x - l, 1, 0, mx);

                // new right interval
                update(r, r - x, 1, 0, mx);

                st.insert(x);
            }

            // Check if block of size sz fits in [0,x]
            else {

                int x = q[1];
                int sz = q[2];

                auto it = st.upper_bound(x);
                --it;

                int pre = *it;

                // largest complete gap before x
                int max_space =
                    query(0, pre, 1, 0, mx);

                // partial gap containing x
                max_space =
                    max(max_space, x - pre);

                ans.push_back(max_space >= sz);
            }
        }

        return ans;
    }
};
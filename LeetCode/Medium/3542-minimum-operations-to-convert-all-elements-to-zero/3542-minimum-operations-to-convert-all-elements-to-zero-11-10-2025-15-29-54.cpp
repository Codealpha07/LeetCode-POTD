class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack <int> s;
        int res=0;
        for (int x : nums) {
            while (!s.empty() && x<s.top()) s.pop();
            if (x==0) continue;
            if (s.empty() || x>s.top()) {
                ++res;
                s.push(x);
            }
        }
        return res;
    }
};
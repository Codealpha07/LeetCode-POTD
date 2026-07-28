class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans = 0;
        for (int i = 1; i < p.size(); i++) {
            // Greedily capture every single daily increase
            if (p[i] > p[i - 1]) {
                ans += p[i] - p[i - 1];
            }
        }
        
        return ans;
    }
};
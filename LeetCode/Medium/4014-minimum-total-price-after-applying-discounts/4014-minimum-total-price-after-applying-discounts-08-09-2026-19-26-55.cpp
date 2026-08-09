class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        int i=0, j=0;
        double ans = 0;
        while(i<prices.size() && j<discounts.size()){
            double p = 1.0*prices[i]*(100-discounts[j])/100.0;
            ans += p;
            i++; j++;
        }
        while(i<prices.size()) ans+=prices[i++];
        return ans;
    }
};
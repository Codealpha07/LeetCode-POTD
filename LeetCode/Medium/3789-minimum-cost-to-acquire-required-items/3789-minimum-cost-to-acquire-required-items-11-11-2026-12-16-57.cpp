
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long both = min(need1, need2);

        // Strategy 1: Buy individual items only
        long long costA = 1LL * need1 * cost1 + 1LL * need2 * cost2;

        // Strategy 2: Buy common items for shared requirements
        long long costB = both * costBoth + 1LL * (need1 - both) * cost1 +
                          1LL * (need2 - both) * cost2;

        // Strategy 3: Buy only type 3 items
        long long costC = 1LL * max(need1, need2) * costBoth;

        return min({costA, costB, costC});
    }
};
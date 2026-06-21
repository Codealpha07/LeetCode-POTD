class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int k = 0;
        for(int i=0; i<costs.size(); i++){
            if(costs[i]<=coins){
                k++;
                coins -= costs[i];
            }
            else break;
        }
        return k;
    }
};
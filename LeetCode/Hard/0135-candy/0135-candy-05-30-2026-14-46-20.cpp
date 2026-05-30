class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int, int>> store(n);
        for(int i=0; i<n; i++){
            store[i] = make_pair(ratings[i], i);
        }
        sort(store.begin(), store.end());
        vector<int> candies(n);
        int total = 0;
        for(auto [rating, i]:store){
            int minNeighbourRating = INT_MAX;
            if(i>0) minNeighbourRating = min(minNeighbourRating, ratings[i-1]);
            if(i<n-1) minNeighbourRating = min(minNeighbourRating, ratings[i+1]);

            if(rating<=minNeighbourRating){
                candies[i] = 1;
                total += 1;
            }
            else{
                int need = 1;
                if(i > 0 && ratings[i]>ratings[i-1])
                    need = max(need, candies[i-1] + 1);

                if(i < n-1 && ratings[i] > ratings[i+1])
                    need = max(need, candies[i+1] + 1);

                candies[i] = need;
                total += need;
            }
        }
        return total;
    }
};
class FoodRatings {
    unordered_map<string, pair<string, int>> food_info; // food -> {cuisine, rating}
    unordered_map<string, set<pair<int, string>>> cuisine_map; // cuisine -> set of {-rating, food} for max heap
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            food_info[foods[i]] = {cuisines[i], ratings[i]};
            cuisine_map[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& [cuisine, oldRating] = food_info[food];
        cuisine_map[cuisine].erase({-oldRating, food});
        cuisine_map[cuisine].insert({-newRating, food});
        oldRating = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisine_map[cuisine].begin()->second;
    }
};
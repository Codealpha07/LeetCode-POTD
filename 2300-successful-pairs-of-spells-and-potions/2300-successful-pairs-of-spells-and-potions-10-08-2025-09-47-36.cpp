int countSuccessfulPairs(vector<int>& potions, int spell, long long success) {
        int left = 0;
        int right = potions.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long long)potions[mid] * spell >= success) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return potions.size() - left;
    }

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector <int> pairs(spells.size());
        sort(potions.begin(), potions.end());
        for(int i=0; i<spells.size(); i++){
            pairs[i] = countSuccessfulPairs(potions, spells[i], success);
        }
        return pairs;
    }
};
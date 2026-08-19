class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int left = 0b11110000; // Seat 2-5
        int middle = 0b11000011; // 4-7
        int right = 0b00001111; // 6-9
        unordered_map<int, int> occupied;
        for (const vector<int>& seat : reservedSeats) {
            if (seat[1] >= 2 && seat[1] <= 9) {
                occupied[seat[0]] |= (1 << (seat[1] - 2)); // Making bitmask for the row
            }
        }
        int ans = (n-occupied.size()) * 2; // For unreserved rows. 
        for (auto& [row, bitmask] : occupied) {
            if (((bitmask | left) == left) || ((bitmask | middle) == middle) ||
                ((bitmask | right) == right)) {
                ++ans;
            }
        }
        return ans;
    }
};
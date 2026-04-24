class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int c1 = 0, c2 = 0, c3 = 0;
        for(auto &move: moves){
            switch(move){
                case 'L':
                c1++; break;
                case 'R':
                c2++; break;
                default:
                c3++; break;
            }
        }
        return abs(c1-c2)+c3;
    }
};
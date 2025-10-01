class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = numBottles;
        int numEmpty = numBottles;
        numBottles = 0;
        while(numEmpty >= numExchange){
            numBottles += numEmpty/numExchange;
            cnt += numBottles;
            numEmpty %= numExchange;
            numEmpty += numBottles;
            numBottles = 0;
        }
        return cnt;
    }
};
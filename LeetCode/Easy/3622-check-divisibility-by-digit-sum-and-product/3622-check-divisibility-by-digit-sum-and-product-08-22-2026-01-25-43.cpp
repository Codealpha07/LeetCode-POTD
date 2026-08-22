class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int dSum = 0, dProd = 1;
        while(temp){
            dSum += temp%10;
            dProd *= temp%10;
            temp /= 10;
        }
        return n%(dSum+dProd)==0;
    }
};
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a=0, b=0;
        for(char c:s) (c=='a') ? a++ : b++;
        int m = min(a, b);
        return s.size()-m*2;
    }
};
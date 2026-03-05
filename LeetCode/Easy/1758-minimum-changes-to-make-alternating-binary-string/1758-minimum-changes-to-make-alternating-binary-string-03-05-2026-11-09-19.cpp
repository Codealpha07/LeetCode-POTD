class Solution {
public:
    int check(int start, string s){
        int op = 0;
        for(char c:s){
            if(c-'0'!=start) op++;
            start=1-start;
        }
        return op;
    }
    int minOperations(string s) {
        return min(check(0,s), check(1,s));
    }
};
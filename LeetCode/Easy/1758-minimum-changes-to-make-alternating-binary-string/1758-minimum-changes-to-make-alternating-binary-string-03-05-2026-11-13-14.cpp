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
        int start0 = check(0,s);
        return min(start0, (int)s.size()-start0);
    }
};
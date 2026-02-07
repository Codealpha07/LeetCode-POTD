class Solution {
public:
    int minimumDeletions(string s) {
        int op = 0;
        stack<char> stk;
        for(int i=0; i<s.length(); i++){
            if(!stk.empty() && stk.top()=='b' && s[i]=='a'){
                stk.pop();
                op++;
            }
            else{stk.push(s[i]);}
        }
        return op;
    }
};
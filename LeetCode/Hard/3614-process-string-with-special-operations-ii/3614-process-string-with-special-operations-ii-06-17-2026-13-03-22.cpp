class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for(auto c:s){
            if(isalpha(c)) len++;
            else if (c=='*'){
                if(len>0) len--;
            }
            else if (c=='#') len*=2;
        }
        if(len<k+1) return '.'; 
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]=='*') len++;
            else if (s[i] == '#') {
                if (k+1>(len+1)/2) {
                    k-=len/2;
                }
                len=(len+1)/2;
            } else if (s[i] == '%') {
                k = len-k-1;
            } else {
                if (k+1==len) return s[i];
                else len--;
            }
        }
        return '.';
    }
};
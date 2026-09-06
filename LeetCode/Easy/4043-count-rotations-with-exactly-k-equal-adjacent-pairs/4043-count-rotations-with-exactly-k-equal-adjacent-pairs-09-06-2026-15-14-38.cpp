class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.length();
        int total = 0;
        for(int i=0; i<n; i++){
            if(s[i] == s[(i+1+n)%n]) total++;
        }
        if(total==k) return n-total;
        if(k==total-1) return total;
        return 0;
    }
};
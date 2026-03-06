class Solution {
public:
    bool checkOnesSegment(string s) {
        int check = 0;
        if(s[0]=='1') check++;
        for(int i=1; i<s.size(); i++){
            if(s[i]=='1' && s[i-1]=='0') check++;
            if(check>1) return false;
        }
        return true;
    }
};
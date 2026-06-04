class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;
        int ans = 0;
        while(i>=0){
            if(s[i]==' ') i--;
            else{
                while(i>=0 && s[i--]!=' ') ans++;
                return ans;
            }
        }
        return 0;
    }
};
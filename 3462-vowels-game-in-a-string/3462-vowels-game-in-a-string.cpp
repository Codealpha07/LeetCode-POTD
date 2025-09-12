class Solution {
public:
    bool doesAliceWin(string s) {
        int vCnt=0;
        for(char c:s){
            if(isVowel(c)) return true;
        }
        return false;
    }
private:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){return true;}
        return false;
    }
};
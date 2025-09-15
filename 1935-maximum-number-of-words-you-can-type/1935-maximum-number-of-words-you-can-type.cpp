class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> m(26,0);
        for(char c:brokenLetters) m[c-'a']=1;
        int i = 0;
        int no = 0, totalWords = 1;
        while(i<text.length()){
            if(text[i]!= ' ' && m[text[i]-'a']==1){
                while(i<text.length() && text[i]!=' ')  i++;
                no++;
            }
            if(i<text.length() && text[i] == ' ') totalWords++;
            i++;
        }
        return totalWords-no;
    }
};

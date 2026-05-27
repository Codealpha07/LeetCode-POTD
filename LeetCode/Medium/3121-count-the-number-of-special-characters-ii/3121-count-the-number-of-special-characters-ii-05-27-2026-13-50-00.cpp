class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> a(26, -1), A(26, -1);
        for(int i=0; i<word.length(); i++){
            if(word[i]>='a') a[word[i]-'a'] = i;  
            else {
                if(A[word[i]-'A'] == -1) A[word[i]-'A'] = i;
            }
        }     
        int count = 0;
        for(int i=0; i<26; i++){
            if(a[i]!=-1 && a[i]<A[i]) count++;
        }
        return count;
    }
};
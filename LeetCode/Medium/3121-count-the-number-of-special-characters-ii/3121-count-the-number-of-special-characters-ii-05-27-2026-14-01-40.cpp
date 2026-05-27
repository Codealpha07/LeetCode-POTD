class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> store(26, -1);
        for(int i=0; i<word.length(); i++){
            if(word[i]>='a'){
                if(store[word[i]-'a']==-1) store[word[i]-'a']=0; 
                if(store[word[i]-'a']==1) store[word[i]-'a']=-2;  
            }
            else {
                if(store[word[i]-'A']==0) store[word[i]-'A']=1;
                else if(store[word[i]-'A']==1) continue;
                else store[word[i]-'A'] = -2;
            }
        }     
        int count = 0;
        for(int i=0; i<26; i++){
            if(store[i]==1) count++;
        }
        return count;
    }
};
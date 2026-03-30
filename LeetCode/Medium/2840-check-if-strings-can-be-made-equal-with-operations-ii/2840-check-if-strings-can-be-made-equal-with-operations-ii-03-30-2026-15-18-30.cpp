class Solution {
public:
    bool checkStrings(string s1, string s2) {
        multiset<char> evenChar, oddChar;
        for(int i = 0; i < s1.length(); i++){
            if(i % 2) oddChar.insert(s1[i]);
            else evenChar.insert(s1[i]);  
        }
        for(int i = 0; i < s2.length(); i++){
            if(i % 2){
                auto it = oddChar.find(s2[i]);
                if(it != oddChar.end()) oddChar.erase(it);
                else return false;
            }
            else{
                auto it = evenChar.find(s2[i]);
                if(it != evenChar.end()) evenChar.erase(it);
                else return false;
            }
        }

        return evenChar.empty() && oddChar.empty();
    }
};
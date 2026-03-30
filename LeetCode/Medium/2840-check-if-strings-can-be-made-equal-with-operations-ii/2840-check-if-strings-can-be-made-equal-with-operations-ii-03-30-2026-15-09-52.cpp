class Solution {
public:
    bool checkStrings(string s1, string s2) {
        multiset<int> evenChar1, oddChar1;
        multiset<int> evenChar2, oddChar2;
        for(int i=0; i<s1.length(); i++){
            if(i%2){
                oddChar1.insert(s1[i]);
                oddChar2.insert(s2[i]); 
            }
            else{
                evenChar1.insert(s1[i]);
                evenChar2.insert(s2[i]); 
            }
        }
        return (evenChar1==evenChar2 && oddChar1==oddChar2);
    }
};
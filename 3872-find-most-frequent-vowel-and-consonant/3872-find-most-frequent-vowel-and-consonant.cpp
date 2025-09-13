class Solution {
public:
    int maxFreqSum(string s) {
        int v=0, co=0;
        unordered_map<char, int> freq;
        for(char c:s){
            freq[c]++;
            if(isVowel(c)) v = max(v, freq[c]);
            else co = max(co, freq[c]);
        }
        return v+co;
    }
private:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
};
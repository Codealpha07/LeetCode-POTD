class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(string s:words){
            int weight = 0;
            for(char c:s){
                weight += weights[c-'a']; 
            }
            weight = weight%26;
            char c = 'z'-weight;
            ans += c;
        }
        return ans;
    }
};
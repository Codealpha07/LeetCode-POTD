class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>m;
        for(char ch:text){
            if(ch=='b'||ch=='a'||ch=='l'||ch=='o'||ch=='n'){
                m[ch]++;
            }
        }
        if(m.size()!=5) return 0;
        int ans=INT_MAX;
        for(auto &x:m){
            if(x.first=='b'||x.first=='a'||x.first=='n') ans=min(ans, x.second/1);
            else if(x.first=='l'||x.first=='o') ans=min(ans, x.second/2);
        }
        return ans;
    }
};
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<pair<int, int>> occur(26, {INT_MAX,INT_MIN});
        for(int i=0; i<n; i++){
            if(occur[s[i]-'a'].first==INT_MAX) occur[s[i]-'a'].first=i;
            occur[s[i]-'a'].second = i;
        }
        int cnt = 0;
        for(int i=0; i<26; i++){
            int first = occur[i].first, last = occur[i].second; 
            if(first<n && last>0 && last-first>1){
                vector<int> unique(26,0);
                for(int i=first+1; i<=last-1; i++){
                    if(unique[s[i]-'a']==false){
                        cnt++;
                        unique[s[i]-'a']=true;
                    }
                }
            }
        }
        return cnt;
    }
};
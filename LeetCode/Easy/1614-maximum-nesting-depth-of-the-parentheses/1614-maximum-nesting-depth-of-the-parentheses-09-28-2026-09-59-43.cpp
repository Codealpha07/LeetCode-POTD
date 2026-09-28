class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int cnt = 0;
        for(char c:s){
            if(c=='('){
                cnt++;
                ans = max(cnt, ans);
            }
            if(c==')') cnt--;
        }
        return ans;
    }
};
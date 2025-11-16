class Solution {
public:
    int numSub(string s) {
        int mod = 1e9+7;
        long long num = 0;
        long long cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] - '0') {
                cnt++;
            }
            else {
                num = (num+(cnt*(cnt + 1))/2)%mod;
                cnt = 0;
            }
        }
        num = (num+(cnt*(cnt + 1))/2)%mod;
        return num;
    }
};
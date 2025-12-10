class Solution {
public:
    const int MOD = 1e9+7;
    int countPermutations(vector<int>& complexity) {
        for(int i=1; i<complexity.size(); i++){
            if(complexity[i]<=complexity[0]) return 0;
        }
        return fact(complexity.size()-1);
    }
private:
    int fact(int n){
        int res = 1;
        for(int i=2; i<=n; i++){
            res = (1LL*res*i)%MOD;
        }
        return res;
    }
};
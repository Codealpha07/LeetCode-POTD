class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnt(n+1, 0); // max value can reach n+1 only
        for(int x:arr){
            cnt[min(x, n)]++;
        }
        int val = 0;
        for(int i=1; i<n+1; i++){
            val = min(i, val+cnt[i]); // as cnt[i] can decrease to any value.
        }
        return val;
    }
};
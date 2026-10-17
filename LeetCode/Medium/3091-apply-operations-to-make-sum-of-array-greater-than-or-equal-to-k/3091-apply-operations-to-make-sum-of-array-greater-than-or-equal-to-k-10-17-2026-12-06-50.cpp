class Solution {
public:
    int minOperations(int k) {
        if(k==1) return 0;
        int ans = INT_MAX;
        
        for(int curr = 1; curr<=k; curr++){
            int op = curr-1; 
            op += (k%curr==0) ? k/curr : ceil((double)k/curr);
            op--;
            ans = min(ans, op);
        }
        return ans;
    }
};
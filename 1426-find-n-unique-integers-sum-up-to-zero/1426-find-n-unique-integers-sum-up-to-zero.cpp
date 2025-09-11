class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        for(int i=1; i<n; i++){
            ans.push_back(i);
        }
        ans.push_back(-1*((n*(n-1))/2));
        return ans;
    }
};
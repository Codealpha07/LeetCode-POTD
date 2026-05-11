class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int n:nums){
            string ns = to_string(n);
            for(auto c:ns){
                ans.push_back(c-'0');
            }
        }
        return ans;
    }
};
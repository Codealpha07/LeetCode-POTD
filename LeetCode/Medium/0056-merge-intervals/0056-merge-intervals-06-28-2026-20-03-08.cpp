class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int l=intervals[0][0], r=intervals[0][1];
        vector<vector<int>> ans;
        for(auto interval:intervals){
            int a=interval[0], b=interval[1];
            if(a<=r) r=max(r, b);
            else{
                ans.push_back({l,r});
                l=a, r=b;
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};
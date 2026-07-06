class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int l = intervals[0][0], r=intervals[0][1];
        int ans = 1;
        for(auto interval:intervals){
            int l1 = interval[0], r1 = interval[1];
            if(r1>r){
                ans++;
                l=l1, r=r1;
            }
        }
        return ans;
    }
private: 
    static bool cmp(const vector<int> &a, const vector<int> &b){
        return (a[0]==b[0]) ? a[1]>b[1] : a[0]<b[0];
    }
};
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int cnt = 0;
        for(auto p:points) cnt+=(p[1]==0);
        return (cnt*(cnt-1))/2;
    }
};
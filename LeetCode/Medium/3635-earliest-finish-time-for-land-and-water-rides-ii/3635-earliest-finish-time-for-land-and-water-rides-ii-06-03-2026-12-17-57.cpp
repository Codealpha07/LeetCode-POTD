class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int LW = INT_MAX, WL = INT_MAX;
        int earlyL = INT_MAX, earlyW = INT_MAX;
        int n = landStartTime.size(), m = waterStartTime.size();

        for(int i=0; i<n; i++){
            earlyL = min(earlyL, landStartTime[i]+landDuration[i]);
        } 
        for(int i=0; i<m; i++){
            earlyW = min(earlyW, waterStartTime[i]+waterDuration[i]);
            
            // If first completing land then water.
            LW = min(LW, max(earlyL, waterStartTime[i])+waterDuration[i]);
        } 
        for(int i=0; i<n; i++){
            // If first completing water then land.
            WL = min(WL, max(earlyW, landStartTime[i])+landDuration[i]);
        } 
        return min(LW, WL);
    }
};
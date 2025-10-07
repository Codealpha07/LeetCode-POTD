class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        map<int, int> lastRainDay;
        vector<int> dryDay;
        for(int i=0; i<n; i++){
            if(rains[i]==0) dryDay.push_back(i+1);
            else{
                if(lastRainDay[rains[i]]==0){
                    lastRainDay[rains[i]]=i+1;
                }
                else{
                    if(dryDay.empty() || (dryDay.back() < lastRainDay[rains[i]])){
                        return {};
                    }
                    ans[dryDay.back()-1] = rains[i];
                    dryDay.pop_back();
                    lastRainDay[rains[i]]=i+1;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(rains[i]==0 && ans[i]==-1) ans[i]=1;
        }
        return ans;
    }
};
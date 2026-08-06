class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size(), m = shifts.size();
        vector<long long> preSum(n);
        preSum[0] = tasks[0];
        for(int i=1; i<n; i++){
            preSum[i] = preSum[i-1]+tasks[i];
        }
        vector<int> ans;
        long long totalTime = preSum[n-1];
        long long currTime = 0;
        for(int i=0; i<m; i++){
            if(currTime+shifts[i] >= totalTime){
                ans.push_back(0); currTime=0;
            }
            else{
                currTime += shifts[i];
                auto x = upper_bound(preSum.begin(), preSum.end(), currTime);
                int left = n-distance(preSum.begin(), x);
                ans.push_back(left);
            }
        }
        return ans;
    }
};
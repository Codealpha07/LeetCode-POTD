class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        for(auto &task:tasks){
            task[0] = task[1]-task[0];
        }
        sort(tasks.begin(), tasks.end(), comp);
        int ans=0, left=0;
        for(auto task:tasks){
            if(left>=task[1]){
                left = left-(task[1]-task[0]);
            }
            else{
                ans += task[1]-left;
                left = task[0];
            }
        }
        return ans;
    }
private:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        else return a[0]>b[0];
    }
};
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> m;
        for(auto r : reservedSeats){
            m[r[0]].push_back(r[1]-1);
        }
        int ans = (n - m.size())*2;
        for(auto r:m){
            vector<int> contains(10);
            for(int x:r.second){
                contains[x]=1;
            }
            bool flag = 0;
            if(!contains[1] && !contains[2] && !contains[3] && !contains[4]){
                ans++; flag = 1;
            }
            if(!contains[5] && !contains[6] && !contains[7] && !contains[8]){
                ans++; flag = 1;
            }
            if(!flag){
                    if(!contains[3] && !contains[4] && !contains[5] && !contains[6]){
                    ans++;
                }
            }
        }
        return ans;
    }
};
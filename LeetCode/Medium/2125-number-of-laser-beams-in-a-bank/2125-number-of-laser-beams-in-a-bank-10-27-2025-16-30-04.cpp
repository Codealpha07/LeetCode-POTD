class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> a;
        for(int i=0; i<bank.size(); i++){
            int count = 0;
            for(int j=0; j<bank[0].size(); j++){
                count+=(bank[i][j]=='1');
            }
            if(count>0) a.push_back(count);
        }
        int ans = 0;
        for(int i=1; i<a.size(); i++){
            ans+=a[i]*a[i-1];
        }
        return ans;
    }
};
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev=0;
        for(int i=0; i<bank.size(); i++){
            int count = 0;
            for(int j=0; j<bank[0].size(); j++){
                count+=(bank[i][j]=='1');
            }
            if(count>0){
                ans+=count*prev;
                prev=count;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev=-1, curr=-1;
        for(int i=0; i<bank.size(); i++){
            int count = 0;
            for(int j=0; j<bank[0].size(); j++){
                count+=(bank[i][j]=='1');
            }
            if(count>0){
                if(curr==-1) curr=count;
                else{
                    prev=curr;
                    curr=count;
                    ans+=curr*prev;
                }
            }
        }
        return ans;
    }
};
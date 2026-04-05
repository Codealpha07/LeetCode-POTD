class Solution {
public:
    bool judgeCircle(string moves) {
        int cntL=0,cntU=0;
        for(auto c:moves){
            if(c=='L') cntL++;
            else if(c=='R') cntL--;
            else if(c=='U') cntU++;
            else cntU--;
        }
        return (cntL==0 && cntU==0); 
    }
};
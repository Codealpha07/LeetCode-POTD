class Solution {
public:
    bool judgeCircle(string moves) {
        int cntL=0,cntR=0,cntU=0, cntD=0;
        for(auto c:moves){
            if(c=='L') cntL++;
            else if(c=='R') cntR++;
            else if(c=='U') cntU++;
            else cntD++;
        }
        return (cntL==cntR && cntU==cntD); 
    }
};
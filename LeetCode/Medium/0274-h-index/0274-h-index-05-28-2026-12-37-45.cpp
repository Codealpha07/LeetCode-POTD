class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l=0, r=citations.size();
        while(l<r){
            int mid = (l+r+1)>>1;
            if(check(citations, mid)) l=mid;
            else r=mid-1;
        }
        return l;
    }
private:
    bool check(vector<int> &citations, int h){
        int cnt = 0;
        for(int i:citations){
            if(i>=h) cnt++;
        }
        return cnt>=h;
    }
};
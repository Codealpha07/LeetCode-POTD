class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> div(102);
        for(int i:nums){
            if(i%k==0) div[i/k]=1;
        }
        for(int i=1; i<=101; i++){
            if(!div[i]) return i*k;
        }
        return -1;
    }
};
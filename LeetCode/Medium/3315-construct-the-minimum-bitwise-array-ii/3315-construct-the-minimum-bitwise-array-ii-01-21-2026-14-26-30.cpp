class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(int &num:nums){
            if(num==2){num=-1; continue;} 
            int count=0; // Number of consecutive 1s from right side 
            int numCopy = num;
            while((num & 1)==1){
                count++;
                num>>=1;
            }
            num = numCopy-(1<<(count-1)); // Unset the leftmost 1 from right 
        }
        return nums;
    }
};
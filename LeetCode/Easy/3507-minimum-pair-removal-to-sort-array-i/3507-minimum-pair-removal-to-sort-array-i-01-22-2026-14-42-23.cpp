class Solution {
public: 
    bool checkIncreasing(vector<int> nums){
        if(nums.size()==1) return true;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    } 
    void fun(vector<int> &copy){
        int idx; int minSum = INT_MAX;
        for(int i=0; i<copy.size()-1; i++){
            if(copy[i]+copy[i+1]<minSum){
                idx = i; minSum=copy[i]+copy[i+1];
            }
        }
        copy[idx] = minSum;
        copy.erase(copy.begin()+idx+1);
    }
    int minimumPairRemoval(vector<int>& nums) {
        int op = 0;
        vector<int> copy = nums;
        while(!(checkIncreasing(copy))){
            op++;
            fun(copy);
        }
        return op;
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]); arr2.push_back(nums[1]); 
        int a=nums[0], b=nums[1]; int i=2;
        while(i<nums.size()){
            if(a>b){
                arr1.push_back(nums[i]);
                a=nums[i++];
            }
            else{
                arr2.push_back(nums[i]);
                b=nums[i++];
            }
        }
        for(int i:arr2){
            arr1.push_back(i);
        }
        return arr1;
    }
};
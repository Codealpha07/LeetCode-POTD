// first principle (brute Force) -> O(n), O(n)

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n-1, 0);
        for(int i:nums){
            if(i<n) freq[i-1]++;
            else return false;
        }
        for(int i=0; i<n-1; i++){
            if(freq[i]==0) return false;
        }
        return (freq[n-2]==2);
    }
};
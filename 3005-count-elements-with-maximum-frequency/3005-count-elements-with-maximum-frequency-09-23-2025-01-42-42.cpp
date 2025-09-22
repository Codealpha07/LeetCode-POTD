class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int max_freq = 0, ans=0;
        for(int x:nums){freq[x]++; max_freq = max(max_freq, freq[x]);}
        for(auto m:freq){ans+=(m.second==max_freq);}
        return ans*max_freq;
    }
};
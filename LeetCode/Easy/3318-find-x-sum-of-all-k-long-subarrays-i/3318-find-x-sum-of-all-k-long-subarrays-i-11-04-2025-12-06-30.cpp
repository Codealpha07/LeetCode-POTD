class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        int idx = 0;
        
        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> freqMap;
            
            for (int j = i; j < i + k; j++) {
                freqMap[nums[j]]++;
            }
            
            vector<pair<int, int>> freq(freqMap.begin(), freqMap.end());
            sort(freq.begin(), freq.end(), [](pair<int, int> &a, pair<int, int> &b) {
                return (a.second != b.second) ? a.second > b.second : a.first > b.first;
            });

            int sum = 0;
            int limit = min(x, (int)freq.size());
            for (int y = 0; y < limit; y++) {
                sum += freq[y].first * freq[y].second;
            }

            ans[i] = sum;
        }
        
        return ans;
    }
};

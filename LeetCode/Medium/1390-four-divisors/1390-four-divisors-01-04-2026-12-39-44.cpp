class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        vector<int> cnt(100001,1); //1
        vector<long long> sum(100001,1);
        cnt[1]=1;
        sum[1]=1;
        for(int i = 2 ; i <= 100000 ; i++)
        {
            for(int j = i ; j <= 100000 ; j+=i)
            {
                cnt[j]++;
                sum[j] += 1LL*i;
            }
        }
        int ans = 0;
        for(int x : nums)
            ans += cnt[x]==4 ? sum[x] : 0;
        return ans;
    }
};
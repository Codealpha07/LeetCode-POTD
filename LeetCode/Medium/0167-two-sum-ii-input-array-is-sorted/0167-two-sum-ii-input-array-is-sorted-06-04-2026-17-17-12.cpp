class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0; i<numbers.size(); i++){
            int num1 = numbers[i];
            int num2 = target-num1;
            auto it = lower_bound(numbers.begin()+i+1, numbers.end(), num2);
            int j = it - numbers.begin();
            if(j<numbers.size() && num2==numbers[j]) return {i+1, j+1};
        }
        return {-1, -1};
    }
};
#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string ans = "";
        
        // 1. Handle signs using XOR. 
        // If one is negative and the other is positive, the result is negative.
        if ((numerator < 0) ^ (denominator < 0)) {
            ans += "-";
        }
        
        // 2. Convert to 64-bit integer (long long) and take absolute value.
        // The cast MUST happen inside abs() to prevent INT_MIN overflow.
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        
        // 3. Process the integral part
        ans += to_string(num / den);
        long long rem = num % den;
        
        // If there is no fractional part, we are done
        if (rem == 0) return ans;
        
        // 4. Process the fractional part
        ans += ".";
        
        // Map to store: {remainder -> index in string where its quotient is added}
        unordered_map<long long, int> rem_map;
        
        while (rem != 0) {
            // If we have seen this remainder before, a cycle has begun
            if (rem_map.find(rem) != rem_map.end()) {
                ans.insert(rem_map[rem], "(");
                ans += ")";
                break; // Cycle found, stop division
            }
            
            // Record the current remainder and the index where its quotient will be placed
            rem_map[rem] = ans.length();
            
            // Standard long division steps
            rem *= 10;
            ans += to_string(rem / den);
            rem %= den;
        }
        
        return ans;
    }
};
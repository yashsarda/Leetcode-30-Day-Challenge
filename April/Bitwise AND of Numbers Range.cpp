/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        int answer = 0;
        if(m == n)
            return m;
        while(m > 0) {
            int power_of_m = (1LL << (int)log2(m));
            int power_of_n = (1LL << (int)log2(n));
            if(power_of_m == power_of_n)
                answer |= (power_of_m);
            m -= power_of_m;
            n -= power_of_m;
        }
        
        return answer;
    }
};
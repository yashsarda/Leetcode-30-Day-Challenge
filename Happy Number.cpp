/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, 
replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay),
 or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.
*/

class Solution {
public:
    long long sum_of_sq(long long n)
    {
        long long answer = 0;
        while(n) {
            int rem = n % 10;
            answer += (rem * 1LL * rem);
            n /= 10;
        }
        return answer;
    }
    bool isHappy(int n) {
        if(n == 1)
            return true;
        set<long long> seen;
        long long answer = 0;
        long long q = n;
        do {
            answer = sum_of_sq(q);
            if(seen.find(answer) != seen.end())
                return false;
            seen.insert(answer);
            q = answer;
        } while(answer != 1);
        
        return true;
    }
};
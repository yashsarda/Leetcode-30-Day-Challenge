/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.
*/

class Solution {
public:
    int findClosestNumber(int num)
    {
        int lower = 0;
        int upper = num;
        
        int answer = 0;
        while(lower <= upper) {
            int mid = lower + (upper - lower) / 2;
            
            if(mid * 1LL * mid > num) {
                upper = mid - 1;
            }
            else {
                answer = mid;
                lower = mid + 1;
            }
        }
        return answer;
    }
    bool isPerfectSquare(int num) {
        int answer = findClosestNumber(num);
        return (answer * answer == num);
        
    }
};
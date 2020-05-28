/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
*/
class Solution {
public:
    bool isPowerOfTwo(int x)
    {
        return (x & (x - 1)) == 0;
    }
    vector<int> countBits(int num) {
        if(num == 0)
            return {0};
        vector<int> answer(num + 1);
        answer[0] = 0;
        answer[1] = 1;

        int nearest_power = -1;
        for(int i = 2; i <= num; i++) {
            if(isPowerOfTwo(i)) {
                nearest_power = i;
            }
            answer[i] = 1 + answer[i - nearest_power];
        }

        return answer;
    }
};

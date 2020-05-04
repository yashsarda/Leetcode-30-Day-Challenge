/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
*/

class Solution {
public:
    int findComplement(int num) {
        int greatest_bit = 0;
        for(int i = 31; i >= 0; i--) {
            if(num & (1LL << i)) {
                greatest_bit = i;
                break;
            }
        }
        for(int i = 0; i <= greatest_bit; i++) {
            num ^= (1 << i);   
        }
        return num;
        
    }
};
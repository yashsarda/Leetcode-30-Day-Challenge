/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
 class Solution {
 public:
     int singleNumber(vector<int>& nums) {
         int answer = 0;

         for(int i = 31; i >= 0; i--) {
             int counter = 0;
             for(int element : nums) {
                 if((1LL << i) & element)
                     counter++;
             }
             if(counter % 3)
                 answer |= (1LL << i);
         }

         return answer;
     }
 };

/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        for(int element : nums) {
            answer ^= element;
        } 
        return answer;
        
    }
};
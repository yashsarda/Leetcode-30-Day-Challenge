/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int answer = nums[0];
        int counter = 1;
        
        for(int i = 1; i < n; i++) {
            if(nums[i] == answer) {
                counter++;
            } 
            else {
                if(counter == 0) {
                    answer = nums[i];
                    counter = 1;
                }
                else {
                    counter--;
                }
            }
        }
        
        return answer;
    }
};
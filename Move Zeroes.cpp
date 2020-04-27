/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return;

        int first_zero = -1;
        int first_non_zero = n + 1;
        for(int i=0;i<n;i++) {
            if(nums[i] == 0) {
                first_zero = i;
                break;
            }
        }
        if(first_zero == -1)
            return;
        for(int i=first_zero+1;i<n;i++) {
            if(nums[i] != 0) {
                first_non_zero = i;
                break;
            }
        }
        
        while(first_non_zero < n) {
            swap(nums[first_zero], nums[first_non_zero]);
            first_zero += 1;
            first_non_zero += 1;
            while(first_zero < n && nums[first_zero] != 0) {
                first_zero++;
            }
            
            while(first_non_zero < n && nums[first_non_zero] == 0) {
                first_non_zero++;
            }
        }
    }
};
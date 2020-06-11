/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.
 */
 class Solution {
 public:
     void sortColors(vector<int>& nums) {
         int n = nums.size();

         int left = 0,  right = n - 1, mid = 0;

         // mid is used for traversing the array
         // left pointer used for swapping 0's
         // right pointer used for swapping 2's
         // [2, 0, 1] = [1, 0, 2] = [1, 0, 2] = [0, 1, 2]
         while(mid <= right) {
             if(nums[mid] == 2) {
                 swap(nums[mid], nums[right--]);
             }
             else if(nums[mid] == 0){
                 swap(nums[mid++], nums[left++]);
             }
             else
                 mid++;
         }
     }
 };

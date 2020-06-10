/*
Given a sorted array and a target value, return the index if the target is found. If not,
return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
 */

 class Solution {
 public:
     int searchInsert(vector<int>& nums, int target) {
         int n = nums.size();
         int lower = 0;
         int upper = n - 1;
         while(lower <= upper) {
             int mid = lower + (upper - lower) / 2;
             if(nums[mid] == target)
                 return mid;
             if(nums[mid] > target)
                 upper = mid - 1;
             else
                 lower = mid + 1;
         }
         return lower;

     }
 };

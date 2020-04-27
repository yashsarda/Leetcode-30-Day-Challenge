/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).
*/
/*
5,0,1,2,3,4 -> 0,1,2,3 and 4,5

4,5,6,7,0,1,2,3
the point where array separates is between 5 and 0


*/
class Solution {
public:
    int binary_search(vector<int>& nums, int start, int end, int target)
    {
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return -1;
        if(n == 1)
            return (nums[0] == target ? 0 : -1);
        
        if(nums[0] < nums.back())
            return binary_search(nums, 0, n - 1, target);
        
        int find_middle = -1;
        int low = 0;
        int high = n - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(mid != 0 && nums[mid] < nums[mid - 1]) {
                find_middle = mid;
                break;
            }
            
            if(nums[mid] < nums.back()) 
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        if(target >= nums[0])
            return binary_search(nums, 0, find_middle - 1, target);
        return binary_search(nums, find_middle, n - 1, target);
        
    }
};
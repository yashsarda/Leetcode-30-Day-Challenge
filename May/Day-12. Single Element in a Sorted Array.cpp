/*
You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once. Find this single element that appears only once.
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lower = 0;
        int upper = nums.size() - 1;
        
        int answer = -1;
        
        while(lower <= upper) {
            int mid = lower + (upper - lower) / 2;
            
            if(mid == 0 || mid == nums.size() - 1)
                return nums[mid];
            
            if(mid % 2 == 0) {
                if(nums[mid] == nums[mid + 1])
                    lower = mid + 1;
                else if(nums[mid] == nums[mid - 1])
                    upper = mid - 1;
                else
                    return nums[mid];
            }
            else {
                if(nums[mid] == nums[mid + 1])
                    upper = mid - 1;
                else if(nums[mid] == nums[mid - 1])
                    lower = mid + 1;
                else
                    return nums[mid];
            }
        }
        return 0;
    }
};
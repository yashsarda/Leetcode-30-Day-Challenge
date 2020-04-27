/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
*/

// Kadane algorithm
// Let dp[i] = maximum sum subarray ending at i
// Transitions :- 
// dp[i] = max(A[i], dp[i - 1] + A[i]);
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int previous = nums[0];
        int current = 0;
        int answer = previous;
        for(int i=1;i<n;i++) {
            current = max(nums[i], previous + nums[i]);
            answer = max(answer, current);
            previous = current;
        }
        return answer;
    }
};
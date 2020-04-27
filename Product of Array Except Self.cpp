/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
*/

/*

[1, 2, 3, 4] 
We can keep running prefix sums easily. How can we keep suffix sums
In 1 loop we will store the prefix sum in answer vector
answer[0] = 1;
answer[1] = 1
answer[2] = 2
answer[3] = 6

Run a loop from end
answer[3] = 6
answer[2] = 8
answer[1] = 12 

*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        if(n == 1)
            return answer;
        /*
        vector<long long> prefix(n, 0), suffix(n, 0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i];
        }
        
        
        suffix[n - 1] = nums.back();
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i];
        }
        
        answer[0] = suffix[1];
        answer[n - 1] = prefix[n - 2];
        
        for(int i = 1; i < n - 1; i++) {
            answer[i] = prefix[i - 1] * suffix[i + 1];
        }
        */
        
        int prefix = nums[0];
        for(int i = 1; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        prefix = nums.back();
        for(int i = n - 2; i >= 0; i--) {
            answer[i] *= prefix;
            prefix *= nums[i];
        }
        return answer;

    }
};
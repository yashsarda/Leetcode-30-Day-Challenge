/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.
*/
/*

[4, 5, 1, 0 , 0 ,2 , 6, 4]
CanJump(i) = CanJump(i + 1), ...,   CanJump(i + A[i]) 
if any one of this gives answer as true then of course we can make the jump


*/
class Solution {
public:
    // dp times out
    vector<int> dp;
    bool canJump(int index, vector<int>& nums)
    {
        if(index == nums.size() - 1)
            return dp[index] = true;
        
        if(index >= nums.size())
            return false;
        
        if(dp[index] != -1)
            return dp[index];
        
        bool answer = false;
        for(int i = index + 1; i <= min((int)nums.size() - 1, index + nums[index]); i++) {
            answer |= canJump(i, nums); 
            if(answer == true)
                return answer;
        }
        
        return dp[index] = answer;
    }
    bool canJump(vector<int>& A) {
        int n = A.size();
        if(n == 1)
            return true;
        dp.resize(n + 5, -1);
        if(A[0] == 0)
            return false;
        // bool answer = canJump(0, nums);
        // First numbers coveres A[0] steps
        int covered_part = A[0];
        int decrease_size_of_covered_part = A[0];

        for(int i = 1; i < n; i++){
            if(i == n - 1)
                return true;
            // If the current number number covers more number of steps than current covered_part the
            // next jump would be to this part
            if(i + A[i] > covered_part)
                covered_part = i + A[i];
            // Decrease the number of elements the current covered_part has covered
            decrease_size_of_covered_part--;
            // If we have covered all the element then it's time to jump and we jump at the element which
            // has the maximum reach in already covered part
            if(decrease_size_of_covered_part == 0){
                decrease_size_of_covered_part = covered_part - i;
                if(decrease_size_of_covered_part == 0)
                    return false;
            }
        }
        return true;
    }
};
/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1)
            return (nums.back() == k ? 1 : 0);
        
        unordered_map<int,int> sum_to_count;
        
        sum_to_count[0] = 1;
        int sum = 0;
        int answer = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum_to_count.find(sum - k) != sum_to_count.end()) {
                answer += sum_to_count[sum - k];
            }
            sum_to_count[sum]++;
        }
        return answer;
    }
};
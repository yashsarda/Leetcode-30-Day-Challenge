/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        m[0] = -1;
        int sum = 0;
        int answer = 0;
        for(int i=0;i<n;i++) {
            sum += (nums[i] == 1 ? 1 : -1);
            if(m.find(sum) == m.end()) {
                m[sum] = i;
            }
            else {
                int index = m[sum];
                answer = max(answer, i - index);
            }
        }
        return answer;
    }
};
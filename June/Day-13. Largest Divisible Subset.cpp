/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return {};
        vector<int> answer;
        sort(nums.begin(), nums.end());
        vector<int> LIS(n, 1);
        LIS[0] = 1;

        int max_len = 1;

        for(int i = 1; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(nums[i] % nums[j] == 0) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                    max_len = max(max_len, LIS[i]);
                }
            }
        }
        // cout << max_len << '\n';

        for(int i = n - 1; i >= 0 && max_len > 0; i--) {
            if(LIS[i] == max_len && (answer.empty() || answer.back() % nums[i] == 0)) {
                answer.push_back(nums[i]);
                max_len--;
            }
        }

        return answer;

    }
};

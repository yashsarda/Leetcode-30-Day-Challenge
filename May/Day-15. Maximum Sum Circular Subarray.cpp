/*
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array. 
 (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  
(Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        vector<int> prefix(n, 0), suffix(n, 0), max_prefix(n, 0);
        
        prefix[0] = A[0];
        max_prefix[0] = A[0];
        
        for(int i = 1; i < n; i++) {
            prefix[i] = A[i] + prefix[i - 1];
            max_prefix[i] = max(max_prefix[i - 1], prefix[i]);
        }
        
        suffix[n - 1] = A[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + A[i];
        }
        
        int answer = INT_MIN;
        int current_sum = A[0];
        int prev_sum = 0;
        
        for(int i = 0; i < n; i++) {
            // Max subarray sum logic
            current_sum = max(A[i], A[i] + prev_sum);
            prev_sum = current_sum;
            answer = max(answer, current_sum);
            // Handle for circular case
            // [.....i,...] = Include + Complete suffix sum from [i + 1... n] + maximum prefix sum
            // in [0...i - 1]
            answer = max(answer, A[i] + (i < n - 1 ? suffix[i + 1] : 0) + (i > 0 ? max_prefix[i - 1] : 0));
        }
        return answer;
    }
};
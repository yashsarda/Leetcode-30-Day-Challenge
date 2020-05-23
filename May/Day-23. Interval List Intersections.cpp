/*
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The
intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.
 For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
*/

class Solution {
public:
    bool nonOverlapping(vector<int>& a, vector<int>& b)
    {
        return (a[1] < b[0] || b[1] < a[0]);
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int len1 = A.size();
        int len2 = B.size();
        vector<vector<int> > answer;
        /*
        O(N * M)
        for(int i = 0; i < len1; i++) {
            for(int j = 0; j < len2; j++) {
                if(nonOverlapping(A[i], B[j])) {
                    if(A[i][1] < B[j][1])
                        break;
                    continue;
                }
                // Overlapping
                answer.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});

            }
        }
        */

        // O(N + M)
        int i = 0;
        int j = 0;

        while(i < len1 && j < len2) {

            int x = max(A[i][0], B[j][0]);
            int y = min(A[i][1], B[j][1]);

            if(x <= y)
                answer.push_back({x, y});

            // If the right endpoint of A interval is smaller than right endpoint of B interval
            // Then it's also going to be smaller than all the left endpoints of intervals after B interval
            // So no overlap
            if(A[i][1] < B[j][1])
                i++;
            else
                j++;
        }
        return answer;
    }
};

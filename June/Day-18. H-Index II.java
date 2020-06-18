/*
Given an array of citations sorted in ascending order
(each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have
 at least h citations each, and the other N − h papers have no more than h citations each."
 */
 class Solution {
     public int hIndex(int[] c) {
         int n = c.length;

         int low = 0;
         int high = n - 1;

         int answer = low;
         while(low <= high) {
             int mid = low + (high - low) / 2;

             // I'm at index mid
             // There are mid numbers behind this and N - mid numbers ahead of this
             // N - mid numbers will have value of >= c[mid]
             // mid numbers will have value of < c[mid]
             if(c[mid] >= n - mid) {
                 answer = n - mid;
                 high = mid - 1;
             }
             else {
                 low = mid + 1;
             }

         }

         return answer;
     }
 }

/*
(This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [rows, cols], which means the matrix is rows * cols.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will
 result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.
*/
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> size_of_matrix = binaryMatrix.dimensions();
        int rows = size_of_matrix[0];
        int columns = size_of_matrix.back();
        
        if(rows == 1 && columns == 1)
            return (binaryMatrix.get(0, 0) == 1 ? 0 : -1);
        
        int min_index = INT_MAX;
        for(int i = 0; i < rows; i++) {
            int lower = 0;
            int higher = columns - 1;
            while(lower <= higher) {
                int mid = lower + (higher - lower) / 2;
                
                int value = binaryMatrix.get(i, mid);
                if(value == 1) {
                    min_index = min(min_index, mid);
                    if(min_index == 0)
                        return 0;
                    higher = mid - 1;
                }
                else {
                    lower = mid + 1;
                }
            }
        }
        
        return (min_index == INT_MAX ? -1 : min_index);
        
    }
};

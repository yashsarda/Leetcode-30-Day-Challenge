/*
Suppose you have a random list of people standing in a queue. Each person is described by a
pair of integers (h, k), where h is the height of the person and k is the
number of people in front of this person who have a height greater than or equal to h.
 Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.
*/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int> > answer;
        int n = people.size();
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
           if(a[0] == b[0])
               return a[1] < b[1];
            return a[0] > b[0];
        });

        vector<int> temp(n + 5, -1);
        for(int i = 0; i < n; i++) {

            if(temp[people[i][1]] == -1) {
                temp[people[i][1]] = i;
            }
            else {
                // Right shift people to occupy correct positions
                // Every time the invariant is maintained when we shift people
                // to the right hand side.
                // The reason begin if a element was at position i and has k elements
                // greater than equal to it, then if we are shifting to the right, it
                // basically means we are adding elements which are smaller at ith position
                // hence the greater elements do not increase
                for(int j = n - 1; j >= people[i][1]; --j) {
                    if(j - 1 >= 0)
                        temp[j] = temp[j - 1];
                }
                temp[people[i][1]] = i;
            }
        }
        for(int i = 0; i < n; i++) {
            answer.push_back(people[temp[i]]);
        }
        return answer;
    }
};

/*
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.
*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int rows = trust.size();
        vector<int> indegree(N + 1, 0), outdegree(N + 1, 0);
        
        for(int i = 0; i < rows; i++) {
            indegree[trust[i][1]]++;
            outdegree[trust[i][0]]++;
        }
        
        for(int i = 1; i <= N; i++) {
            if(indegree[i] == N - 1 && outdegree[i] == 0)
                return i;
        }
        return -1;
    }
    
};
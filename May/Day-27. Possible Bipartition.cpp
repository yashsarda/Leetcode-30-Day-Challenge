/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group.

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.
*/
class Solution {
public:
    vector<vector<int> > graph;
    vector<bool> visited;

    void init(int N)
    {
        graph.clear();
        visited.clear();
        graph.resize(N);
        visited.resize(N, false);
    }
    bool dfs(int node, unordered_set<int>& group0, unordered_set<int>& group1, int expected)
    {
        visited[node] = true;
        if(!expected)
            group0.insert(node);
        else
            group1.insert(node);

        bool answer = true;
        for(int child : graph[node]) {
            int required = !expected;
            // Already visited which means present in some group
            // If the required group does not match with the group that child is present in
            // return false
            if(visited[child]) {
                if(!required && group1.find(child) != group1.end())
                    return false;
                if(required && group0.find(child) != group0.end())
                    return false;
            }
            else {
                answer &= dfs(child, group0, group1, required);
            }
        }
        return answer;
    }
    bool possibleBipartition(int N, vector<vector<int>>& d) {
        int n = d.size();
        if(n == 0)
            return true;
        init(N + 1);
        for(int i = 0; i < n; i++) {
            graph[d[i][0]].push_back(d[i][1]);
            graph[d[i][1]].push_back(d[i][0]);
        }

        bool answer = true;
        unordered_set<int> group0, group1;
        for(int i = 0; i < n; i++) {
            if(!visited[d[i][0]]) {
                answer &= dfs(d[i][0], group0, group1, 0);
            }
        }
        return answer;
    }
};

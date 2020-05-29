/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
*/
class Solution {
public:
    bool dfs(int node, vector<vector<int> >& graph, vector<bool>& visited, vector<bool>& stack)
    {
        visited[node] = true;
        stack[node] = true;

        bool answer = true;

        for(int child : graph[node]) {
            if(!visited[child]) {
                answer &= dfs(child, graph, visited, stack);
            }
            else if(stack[child])
                answer &= false;
        }
        stack[node] = false;
        return answer;
    }
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        if(p.empty())
            return true;
        vector<vector<int> > graph(numCourses);

        for(int i = 0; i < p.size(); i++) {
            int from = p[i][1];
            int to = p[i][0];
            graph[from].push_back(to);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> stack(numCourses, false);
        bool answer = true;
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                answer &= dfs(i, graph, visited, stack);
            }
        }

        return answer;
    }
};

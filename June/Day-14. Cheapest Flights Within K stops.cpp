/*
There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.
Now given all the cities and flights, together with starting city src and the destination dst,
 your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.
 */
 class Solution {
 public:
     struct node {
         int dest;
         int weight;
     };
     vector<vector<node> > graph;
     vector<vector<int> > dp;
     int edges;
     void init(int n, int K)
     {
         graph.clear();
         dp.clear();
         graph.resize(n);
         dp.resize(n);
         for(int i = 0; i < n; i++)
             dp[i].resize(K + 5, INT_MAX);
     }
     int findMinPath(int u, int v, int K)
     {
         if(K == -1)
             return (u != v ? 1e9 : 0);

         if(u == v)
             return 0;

         if(dp[u][K] != INT_MAX)
             return dp[u][K];

         int answer = 1e9;
         for(node child : graph[u]) {
             answer = min(answer, child.weight + findMinPath(child.dest, v, K - 1));
         }
         return dp[u][K] = answer;
     }
     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
         init(n, K);
         edges = flights.size();
         for(int i = 0; i < edges; i++) {
             int from = flights[i][0];
             int to = flights[i][1];
             int weight = flights[i][2];
             graph[from].push_back({to, weight});
         }
         int answer = findMinPath(src, dst, K);
         return (answer == 1e9 ? -1 : answer);

     }
 };

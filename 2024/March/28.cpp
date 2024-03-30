/*
City With the Smallest Number of Neighbors at a Threshold Distance

PROBLEM STATEMENT :

There are n cities labeled from 0 to n-1 with m edges connecting them. Given the array edges 
where edges[i] = [fromi , toi ,weighti]  represents a bidirectional and weighted edge between cities fromi and toi, 
and given the integer distanceThreshold. You need to find out a city with the smallest number of cities that are 
reachable through some path and whose distance is at most Threshold Distance. If there are multiple such cities, our answer 
will be the city with the greatest label.

Note: The distance of a path connecting cities i and j is equal to the sum of the edge's weights along that path.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findCity( ) which takes a number of nodes n, total number of edges m and vector of edges and distanceThreshold. and return the city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance. If there are multiple such cities, return the city with the greatest label.

Expected Time Complexity: O(n2 + length(edges)*nlog(n) )
Expected Auxiliary Space:  O(n3)

Constraints:
1  ≤  n ≤  100
1 <= m <= n*(n-1)/2
length(edges[i]) == 3
0 <= from i < to i < n
1 <= weighti distanceThreshold <= 10^4
All pairs (fromi, toi) are distinct

CODE : 
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++
class Solution {
  public:
    // Function to implement Dijkstra's algorithm to find the shortest distance
    // from source node to all other nodes
    int dijkstra(int n, vector<vector<pair<int, int>>>& graph, int k, int src) {

        // Initializing a queue for BFS traversal
        priority_queue<int> q;
        q.push(src);

        // Initializing a vector to store the minimum distance from the source
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // BFS traversal
        while (!q.empty()) {
            int node = q.top();
            q.pop();

            // Updating the minimum distance for each neighbor node
            for (auto x : graph[node]) {
                int nbr = x.first;
                int wt = x.second;
                if (dist[nbr] > dist[node] + wt) {
                    dist[nbr] = dist[node] + wt;
                    q.push(nbr);
                }
            }
        }

        // Counting the number of cities within the distance threshold
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= k)
                c++;
        }
        return c;
    }

    // Function to find the city with the minimum number of cities within
    // the distance threshold
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Initializing a graph using adjacency list representation
        vector<vector<pair<int, int>>> graph(n);

        // Adding the edges to the graph
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        // Initializing a vector to store the number of cities within the distance
        // threshold
        vector<int> dis(n, 0);

        // Finding the number of cities within the distance threshold for each city
        for (int i = 0; i < n; i++) {
            dis[i] = dijkstra(n, graph, distanceThreshold, i);
        }

        // Finding the city with the minimum number of cities within the distance
        // threshold
        int ans = INT_MAX;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (ans >= dis[i]) {
                ans = dis[i];
                idx = i;
            }
        }
        return idx;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends
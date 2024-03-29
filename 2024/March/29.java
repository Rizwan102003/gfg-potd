/*
 * Euler Circuit in an Undirected Graph
 * 
 * PROBLEM STATEMENT
 * 
 * Eulerian Path is a path in a graph that visits every edge exactly once. Eulerian Circuit is an Eulerian Path that starts and ends on the same vertex. Given the number of vertices v and adjacency list adj denoting the graph. Find that there exists the Euler circuit or not. Return 1 if there exist  alteast one eulerian path else 0.
 * 
 * Your Task:
You don't need to read or print anything. Your task is to complete the function isEularCircuitExist() which takes v and adjacency list adj[] as input parameter and returns boolean value 1 if Eular circuit exists otherwise returns 0.

Expected Time Complexity: O(v + e)
Expected Space Complexity: O(v)

Constraints:
1 <= v <= 105
1 <= edges <= 2*105

CODE (JAVA)
 */

 //{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int V = Integer.parseInt(s[0]);
            int E = Integer.parseInt(s[1]);
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++) adj.add(i, new ArrayList<Integer>());
            for (int i = 0; i < E; i++) {
                String[] S = br.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                adj.get(u).add(v);
                adj.get(v).add(u);
            }
            Solution obj = new Solution();
            boolean ans = obj.isEularCircuitExist(V, adj);
            if (ans)
                System.out.println("1");
            else
                System.out.println("0");
        }
    }
}
// } Driver Code Ends

class Solution {
    // Method to check if an Eulerian circuit exists in a graph
    public boolean isEularCircuitExist(int V, ArrayList<ArrayList<Integer>> adj) {
        // Iterate through all vertices in the graph
        for (int i = 0; i < adj.size(); i++) {
            // Get the number of neighbors of the current vertex
            int listSize = adj.get(i).size();
            // If the number of neighbors is not even, return false
            if (listSize % 2 != 0) {
                return false;
            }
        }
        // Return true if all vertices have even degrees
        return true;
    }
}

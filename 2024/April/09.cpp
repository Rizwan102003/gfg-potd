/*
Minimum Points To Reach Destination

PROBLEM STATEMENT :
Given a m*n grid with each cell consisting of positive, negative, or zero point. We can move across a cell only if we have positive points. Whenever we pass through a cell, points in that cell are added to our overall points, the task is to find minimum initial points to reach cell (m-1, n-1) from (0, 0) by following these certain set of rules :
1. From a cell (i, j) we can move to (i + 1, j) or (i, j + 1).
2. We cannot move from (i, j) if your overall points at (i, j) are <= 0.
3. We have to reach at (n-1, m-1) with minimum positive points i.e., > 0.

EXAMPLE 1 :
Input: 
m = 3, n = 3 
points = {{-2,-3,3}, 
          {-5,-10,1},
          {10,30,-5}} 
Output: 
7 
Explanation: 7 is the minimum value to reach the destination with positive throughout the path. Below is the path. (0,0) -> (0,1) -> (0,2) -> (1, 2) -> (2, 2) We start from (0, 0) with 7, we reach (0, 1) with 5, (0, 2) with 2, (1, 2) with 5, (2, 2) with and finally we have 1 point (we needed greater than 0 points at the end).

EXAMPLE 2 :
Input:
m = 3, n = 2
points = {{2,3},  
          {5,10},  
          {10,30}} 
Output: 
1 
Explanation: Take any path, all of them are positive. So, required one point at the start

Your Task:  
You don't need to read input or print anything. Complete the function minPoints() which takes m,n and 2-d vector points as input parameters and returns the minimum initial points to reach cell (m-1, n-1) from (0, 0).

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ m ≤ 10^3  
1 ≤ n ≤ 10^3
-103 ≤ points[i][j] ≤ 10^3

CODE :
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{

	public:
		int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	    // dp[i][j] represents the minimum initial points player 
	    // should have so that when starts with cell(i, j) successfully 
	    // reaches the destination cell(m-1, n-1) 

	    int dp[m][n];
	  
	    // Base case 
	    dp[m-1][n-1] = points[m-1][n-1] > 0? 1: 
	                   abs(points[m-1][n-1]) + 1; 
	  
	    // Fill last row and last column as base to fill 
	    // entire table 
	    for (int i = m-2; i >= 0; i--) 
	         dp[i][n-1] = max(dp[i+1][n-1] - points[i][n-1], 1); 
	    for (int j = n-2; j >= 0; j--) 
	         dp[m-1][j] = max(dp[m-1][j+1] - points[m-1][j], 1); 
	  
	    // fill the table in bottom-up fashion 
	    for (int i=m-2; i>=0; i--) 
	    { 
	        for (int j=n-2; j>=0; j--) 
	        { 
	            int min_points_on_exit = min(dp[i+1][j], dp[i][j+1]); 
	            dp[i][j] = max(min_points_on_exit - points[i][j], 1); 
	        } 
	     } 
	  
	     return dp[0][0]; 
	} 
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends